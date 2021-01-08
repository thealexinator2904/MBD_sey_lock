function TraceInfoFlag() {
    this.traceFlag = new Array();
    this.traceFlag["keypad_template.c:38c32"]=1;
    this.traceFlag["keypad_template.h:92c10"]=1;
}
top.TraceInfoFlag.instance = new TraceInfoFlag();
function TraceInfoLineFlag() {
    this.lineTraceFlag = new Array();
    this.lineTraceFlag["keypad_template.c:38"]=1;
    this.lineTraceFlag["keypad_template.c:41"]=1;
    this.lineTraceFlag["keypad_template.h:85"]=1;
    this.lineTraceFlag["keypad_template.h:86"]=1;
    this.lineTraceFlag["keypad_template.h:91"]=1;
    this.lineTraceFlag["keypad_template.h:92"]=1;
    this.lineTraceFlag["keypad_template.h:93"]=1;
}
top.TraceInfoLineFlag.instance = new TraceInfoLineFlag();
