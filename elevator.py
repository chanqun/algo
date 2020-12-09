import requests
import json

url = "http://localhost:8000"

def start(user, problem, count):
    uri = url + '/start/' + user + '/' + str(problem) + '/' + str(count)
    return requests.post(uri).json()

def oncalls(token):
    uri = url + '/oncalls'
    return requests.get(uri, headers={'X-Auth-Token': token}).json()

def action(token, cmds):
    uri = url + '/action'
    return requests.post(uri,headers = {'X-Auth-Token' : token}, json = {'commands' : cmds}).json()

def simulator():
    user = 'tester'
    problem = 1
    count = 4
    maxHeight = [5,25,25]
    ret = start(user, problem, count)
    token = ret['token']
    elev_dir = [0]*count   #0 : up 1: down
    elevator_post = []
    for i in range(count):
        elevator_post.append({'elevator_id':i, 'command':'STOP', 'call_ids':[]})

    while(1):
        used = [False]*count
        info = oncalls(token)
        if info['is_end']:
            break
        for idx, elv in enumerate(info['elevators']):
            for pas in elv['passengers']:
                if elv['floor']==pas['end']:
                    if elv['status']=="UPWARD" and not used[idx]:
                        used[idx] = True
                        elevator_post[idx]['command'] = "STOP" 
                    elif elv['status']=="DOWNWARD" and not used[idx]:
                        used[idx] = True
                        elevator_post[idx]['command'] = "STOP"
                    elif elv['status']=="STOPPED" and not used[idx]:
                        used[idx] = True
                        elevator_post[idx]['command'] = "OPEN"
                    elif elv['status']=="OPENED" and (not used[idx] or elevator_post[idx]['command'] == "EXIT"):
                        used[idx] = True
                        elevator_post[idx]['command'] = "EXIT"
                        elevator_post[idx]['call_ids'].append(pas['id'])
        
        for cal in info['calls']:
            for i in range(count):
                elv = info['elevators'][i]
                if (len(elv['passengers'])+len(elevator_post[i]['call_ids']))>=8:
                    continue
                if elv['floor']==cal['start']:
                    if not used[i] and elv['status']=="UPWARD":
                        used[i] = True
                        elevator_post[i]['command'] = "STOP"
                        break
                    elif not used[i] and elv['status']=="DOWNWARD":
                        used[i] = True
                        elevator_post[i]['command'] = "STOP"
                        break
                    elif not used[i] and elv['status']=="STOPPED":
                        used[i] = True
                        elevator_post[i]['command'] = "OPEN"
                        break
                    elif (not used[i] or elevator_post[i]['command'] == "ENTER") and elv['status']=="OPENED":
                        used[i] = True
                        elevator_post[i]['command'] = "ENTER"
                        elevator_post[i]['call_ids'].append(cal['id'])
                        break

        for i in range(count):
            if not used[i]:
                elv = info['elevators'][i]
                if elv['status']=="OPENED":
                    elevator_post[i]['command'] = "CLOSE"
                elif elv['status']=="UPWARD":
                    if elv['floor']==maxHeight[problem]:
                        elevator_post[i]['command'] = "STOP"
                        elev_dir[i] = 1
                    else:
                        elevator_post[i]['command'] = "UP"
                elif elv['status']=="DOWNWARD":
                    if elv['floor']==1:
                        elevator_post[i]['command'] = "STOP"
                        elev_dir[i] = 0
                    else:
                        elevator_post[i]['command'] = "DOWN"
                else:
                    if elv['floor']==maxHeight[problem]:
                        elevator_post[i]['command'] = "DOWN"
                    elif elv['floor']==1:
                        elevator_post[i]['command'] = "UP"
                    else:
                        if elev_dir[i]==0:
                            elevator_post[i]['command'] = "UP"
                        else:
                            elevator_post[i]['command'] = "DOWN"

        _ = action(token, elevator_post)
        for i in range(count):
            print(info['elevators'][i]['floor'], end = ' ')
            elevator_post[i]['call_ids'] = []
        print()





if __name__ == "__main__":
    simulator()
