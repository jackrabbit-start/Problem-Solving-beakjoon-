#include <stdio.h>
#include <string.h>

int main() {

  int n, var1 = 0, var2 = 0;
  char ps[52];
  scanf("%d", &n);
  int res[n];
  for (int i = 0; i < n; i++) {
    scanf("%s", ps);
    for (int j = 0; j < strlen(ps); j++) {
      if ('(' == ps[j]) {
        var1++;
      }
      if (')' == ps[j]) {
        var2++;
      }
      if (ps[0] == ')' || ps[strlen(ps)-1] == '(') {
        var1 = -1;
      }
      if (var1 == var2) {
        if (ps[j + 1] == ')') {
          var1 = -1;
        }
      }
    }
    if (var1 == var2) {
      res[i] = 1;
      var1 = 0, var2 = 0;
    }
    if (var1 != var2) {
      res[i] = 0;
      var1 = 0, var2 = 0;
    }
  }
  for (int i = 0; i < n; i++) {
    if (res[i] == 1) {
      printf("YES\n");
    } else
      printf("NO\n");
  }
  return 0;
}