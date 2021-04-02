package solve;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;

import org.json.simple.JSONArray;
import org.json.simple.JSONObject;
import org.json.simple.parser.JSONParser;

public class ApiCall {
	String HOST_URL = "http://localhost:8000";
	String token ="";
	
	public JSONObject startAPI(String user_key,String problem_id,String number_of_elevators) {
		HttpURLConnection conn = null;
		JSONObject response = null;
		 try {
		        //URL 설정
		        URL url = new URL(this.HOST_URL + "/start"+"/"+user_key+"/"+problem_id+"/"+
		        number_of_elevators);

		        conn = (HttpURLConnection) url.openConnection();
		        conn.setRequestMethod("POST");
		        int responseCode = conn.getResponseCode();
		        if (responseCode == 400) {
		            System.out.println("400:: 해당 명령을 실행할 수 없음 (실행할 수 없는 상태일 때, 엘리베이터 수와 Command 수가 일치하지 않을 때, 엘리베이터 정원을 초과하여 태울 때)");
		        } else if (responseCode == 401) {
		            System.out.println("401:: X-Auth-Token Header가 잘못됨");
		        } else if (responseCode == 500) {
		            System.out.println("500:: 서버 에러, 문의 필요");
		        } else { // 성공 후 응답 JSON 데이터받기
		            BufferedReader br = new BufferedReader(new InputStreamReader(conn.getInputStream()));
		            StringBuilder sb = new StringBuilder();
		            String line = "";
		            while ((line = br.readLine()) != null) {
		                sb.append(line);
		            }
		            response = new JSONObject();
		            JSONParser parser = new JSONParser();
		            response = (JSONObject)parser.parse(sb.toString());
		        }
		    } catch (MalformedURLException e) {
		        e.printStackTrace();
		    } catch (IOException e) {
		        e.printStackTrace();
		    } catch (Exception e) {
		    	e.printStackTrace();
		    }
		 this.token=(String)response.get("token");
		 return response;
	}
	
	public JSONObject onCallsAPI() {
		HttpURLConnection conn = null;
		JSONObject response = null;
	    try {
	        
	        URL url = new URL(this.HOST_URL + "/oncalls");
	        conn = (HttpURLConnection) url.openConnection();
	        conn.setRequestMethod("GET");
	        conn.setRequestProperty("X-Auth-Token", this.token);
	        conn.setDoOutput(true);
	        
	        int responseCode = conn.getResponseCode();
	        if (responseCode == 400) {
	            System.out.println("400:: 해당 명령을 실행할 수 없음 (실행할 수 없는 상태일 때, 엘리베이터 수와 Command 수가 일치하지 않을 때, 엘리베이터 정원을 초과하여 태울 때)");
	        } else if (responseCode == 401) {
	            System.out.println("401:: X-Auth-Token Header가 잘못됨");
	        } else if (responseCode == 500) {
	            System.out.println("500:: 서버 에러, 문의 필요");
	        } else { // 성공
	            BufferedReader br = new BufferedReader(new InputStreamReader(conn.getInputStream()));
	            StringBuilder sb = new StringBuilder();
	            String line = "";
	            while ((line = br.readLine()) != null) {
	                sb.append(line);
	            }
	            
	           // response = new JSONObject(sb.toString());
	            response=new JSONObject();
	            JSONParser parser = new JSONParser();
	            response = (JSONObject)parser.parse(sb.toString());
	        }
	    } catch (MalformedURLException e) {
	        e.printStackTrace();
	    } catch (IOException e) {
	        e.printStackTrace();
	    } catch (Exception e) {
	        e.printStackTrace();
	    }
	    return response;
	}
	
	public JSONObject actionAPI(String jsonText) {	
		HttpURLConnection conn = null;
		JSONObject response = null;
	    try {
	        //URL 설정
	        URL url = new URL(this.HOST_URL + "/action");

	        conn = (HttpURLConnection) url.openConnection();
	        //Request 형식 설정
	        conn.setRequestMethod("POST");
	        conn.setRequestProperty("X-Auth-Token", this.token);
	        conn.setRequestProperty("Content-Type", "application/json");
	        
	        
	        //request에 JSON data 준비
	        conn.setDoOutput(true);
	        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(conn.getOutputStream()));
	        //commands라는 JSONArray를 담을 JSONObject 생성
	        //request에 쓰기
	        bw.write(jsonText);//여기에 넣기
	        bw.flush();
	        bw.close();
	        
	        //보내고 결과값 받기
	        int responseCode = conn.getResponseCode();
	        if (responseCode == 400) {
	            System.out.println("400:: 해당 명령을 실행할 수 없음 (실행할 수 없는 상태일 때, 엘리베이터 수와 Command 수가 일치하지 않을 때, 엘리베이터 정원을 초과하여 태울 때)");
	        } else if (responseCode == 401) {
	            System.out.println("401:: X-Auth-Token Header가 잘못됨");
	        } else if (responseCode == 500) {
	            System.out.println("500:: 서버 에러, 문의 필요");
	        } else { // 성공 후 응답 JSON 데이터받기
	            BufferedReader br = new BufferedReader(new InputStreamReader(conn.getInputStream()));
	            StringBuilder sb = new StringBuilder();
	            String line = "";
	            while ((line = br.readLine()) != null) {
	                sb.append(line);
	            }
	            
	            response = new JSONObject();
	            JSONParser parser = new JSONParser();
	            response = (JSONObject)parser.parse(sb.toString());
	            
	        }
	    } catch (MalformedURLException e) {
	        e.printStackTrace();
	    } catch (IOException e) {
	        e.printStackTrace();
	    } catch (Exception e) {
	        e.printStackTrace();
	    }
	    return response;
	}

}