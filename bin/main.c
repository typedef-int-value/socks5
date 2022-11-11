#include <socks5.h>
#include <stdio.h>

int main(int argc, char** argv)
{
  if (argc != 3)
    return -1;

  printf("connect");

  socks5_t socks5 = { 0 };
  socks5.fd = socket(AF_INET, SOCK_STREAM, 0);
  if (socks5.fd == -1) {
    printf("fd fail\r\n");
    return -1;
  }

  struct sockaddr_in addr = { 0 };
  addr.sin_addr.s_addr = inet_addr("192.168.1.100");
  addr.sin_family = AF_INET;
  addr.sin_port = htons(1080);
  if (connect(socks5.fd, (struct sockaddr*)&addr, sizeof(addr)) == -1)
    return -1;
  socks5_set_command(&socks5, 0x01);
  socks5_set_address(&socks5, argv[1], 8365);
  socks5_connect(&socks5);

  while (1) {
    char buffer[255] = {};
    write(socks5.fd, "abc", 3);

    read(socks5.fd, buffer, 3);
    printf("loop");

    sleep(1);
  }


  printf("success\r\n");

  return 0;
}
