extern int main(void);

//reset handler
__attribute__((naked, noreturn, section(".text.boot"))) void boot(void) {
  //call main()
  main();
  for (;;) (void) 0;  // Infinite loop
}