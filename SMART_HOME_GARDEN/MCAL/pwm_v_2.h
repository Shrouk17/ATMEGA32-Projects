
/********

this function is used to initialize the PWM using timer 0 

this function takes no parameters and has no return 
******/
void pwm_init (void);


/********
this function is used to set the duty cycle value of the PWM
this function takes one  parameter  and has no return 
******/
void pwm_SetDutyCycle (unsigned char );


/********
this function is used to put the function that will run in the compare match interrupt
this function takes one  parameter  and has no return 
******/
void Pwm_setcallback_comparematch (void(*ptr)(void));



/********
this function is used to put the function that will run in the overflow interrupt
this function takes one  parameter  and has no return 
******/
void Pwm_setcallback_overflow (void(*ptr)(void));

