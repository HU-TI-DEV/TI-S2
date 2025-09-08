## Dubbele for-loop

Uiteraard kan je for-loops ook in elkaar plaatsen ('nesting loops'). 

```cpp {.line-numbers}
#include <iostream>
using namespace std;

int main(){
    for (int k=1; k < 10; k++) {
        for(int i=0; i < k; i++) {
            cout << "#";
        }
        cout << "\n";
    }
}
```
*Codevoorbeeld 5.8 dubbele-for-loop*

<details>
  <summary>Output</summary>

  ```cpp {.line-numbers}
#
##
###
####
#####
######
#######
########
#########
  ```
</details>
