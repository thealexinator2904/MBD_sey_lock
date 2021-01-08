function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "keypad_template"};
	this.sidHashMap["keypad_template"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "keypad_template:94"};
	this.sidHashMap["keypad_template:94"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<Root>/Data Type Conversion"] = {sid: "keypad_template:5"};
	this.sidHashMap["keypad_template:5"] = {rtwname: "<Root>/Data Type Conversion"};
	this.rtwnameHashMap["<Root>/Place here the Sequence Lock"] = {sid: "keypad_template:94"};
	this.sidHashMap["keypad_template:94"] = {rtwname: "<Root>/Place here the Sequence Lock"};
	this.rtwnameHashMap["<Root>/S-Function Builder"] = {sid: "keypad_template:1"};
	this.sidHashMap["keypad_template:1"] = {rtwname: "<Root>/S-Function Builder"};
	this.rtwnameHashMap["<Root>/Scope"] = {sid: "keypad_template:112"};
	this.sidHashMap["keypad_template:112"] = {rtwname: "<Root>/Scope"};
	this.rtwnameHashMap["<S1>/Sequence"] = {sid: "keypad_template:95"};
	this.sidHashMap["keypad_template:95"] = {rtwname: "<S1>/Sequence"};
	this.rtwnameHashMap["<S1>/Unlocked"] = {sid: "keypad_template:96"};
	this.sidHashMap["keypad_template:96"] = {rtwname: "<S1>/Unlocked"};
	this.rtwnameHashMap["<S1>/Locked"] = {sid: "keypad_template:98"};
	this.sidHashMap["keypad_template:98"] = {rtwname: "<S1>/Locked"};
	this.rtwnameHashMap["<S1>/State"] = {sid: "keypad_template:99"};
	this.sidHashMap["keypad_template:99"] = {rtwname: "<S1>/State"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
