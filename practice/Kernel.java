import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

class Solution {
	private HashMap<String, String> flagRulesMap = new HashMap<>();
	private HashMap<String, String> aliasMap = new HashMap<>();
	private String stringPattern = "^[a-zA-Z]*$";
	private String numberPattern = "^[0-9]*$";

	public boolean[] solution(String program, String[] flag_rules, String[] commands) {
		boolean[] answer = {};
		List<Boolean> boolList = new ArrayList<>();

		insertFlagRule(flag_rules);

		for (String command : commands) {
			boolList.add(isValidateCommands(program, command));
		}

		answer = new boolean[boolList.size()];
		for (int i = 0; i < boolList.size(); i++) {
			answer[i] = boolList.get(i);
		}

		return answer;
	}

	private void insertFlagRule(String[] flag_rules) {
		for (String flag_rule : flag_rules) {
			String[] flagRule = flag_rule.split(" ");
            int isAliasCommand = 3;

			if (flagRule.length == isAliasCommand) {
				String aliasName = flagRule[0];
				String flagName = flagRule[2];

				aliasMap.put(flagName, aliasName);
				if (flagRulesMap.containsKey(flagName)) {
					String flagArgument = flagRulesMap.get(flagName);
					flagRulesMap.put(aliasName, flagArgument);
				}
                
			} else {
                String flagName = flagRule[0];
				String flagArgument = flagRule[1];
				flagRulesMap.put(flagName, flagArgument);

				if (aliasMap.containsKey(flagName)) {
					flagName = aliasMap.get(flagName);
					flagRulesMap.put(flagName, flagArgument);
				}
			}
		}
	}

	private boolean isValidateCommands(String program, String command) {
		String[] splitCommand = command.split(" ");

		if (!splitCommand[0].equals(program)) {
			return false;
		}

		for (int commandIndex = 1; commandIndex < splitCommand.length; commandIndex++) {
			String beforeCommand = splitCommand[commandIndex - 1];
			String nowCommand = splitCommand[commandIndex];
			String nextCommand = "DEFAULT_COMMAND1";

			if (commandIndex < splitCommand.length - 1) {
				nextCommand = splitCommand[commandIndex + 1];
			}
			
			if(aliasMap.containsKey(nowCommand)) {
				return false;
			}

			if (nowCommand.charAt(0) == '-') {
				String rules = flagRulesMap.get(nowCommand);
				if (rules.equals("STRING")) {
					if (!nextCommand.matches(stringPattern)) {
						return false;
					}
					commandIndex++;

				} else if (rules.equals("NUMBER")) {
					if (!nextCommand.matches(numberPattern)) {
						return false;
					}
					commandIndex++;

				} else if (rules.equals("NULL")) {
					if (commandIndex == splitCommand.length - 1) {
						return true;
					}

					if (nextCommand.charAt(0) != '-') {
						return false;
					}
				} else if (rules.equals("NUMBERS")) {
                    //NUMBER가 연속으로 나오는지 확인 -가 나오는 경우는 break하고 다음으로
					while (true) {
						commandIndex++;

						if (commandIndex == splitCommand.length || splitCommand[commandIndex].charAt(0) == '-') {
							commandIndex--;
							break;
						}

						if (!splitCommand[commandIndex].matches(numberPattern)) {
							return false;
						}
					}

				} else if (rules.equals("STRINGS")) {
                    //STRING이 연속으로 나오는지 확인 -가 나오는 경우는 break하고 다음으로
					while (true) {
						commandIndex++;

						if (commandIndex == splitCommand.length || splitCommand[commandIndex].charAt(0) == '-') {
							commandIndex--;
							break;
						}

						if (!splitCommand[commandIndex].matches(stringPattern)) {
							return false;
						}
					}

				}
			} else {
                //for문을 돌면서 -명령어만 나오게 처리하였으므로 -가 아닌경우 false
				return false;
			}
		}

		return true;
	}
}