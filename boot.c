extern int main(void);

__attribute__((naked, noreturn, section(".text.boot"))) void boot(void) {
  main();
  for (;;) (void) 0;
}