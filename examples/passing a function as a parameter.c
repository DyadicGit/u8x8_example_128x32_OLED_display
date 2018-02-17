
// need forward declarations here
void function2();
void function1(void (*)());


void loop() {
    function1(function2);
}

void function1(void (*function)()){
     (*function)();
}

void function2() {
    //do something
}