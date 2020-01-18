#include <iostream>
using namespace std;
struct pnode {
  int data;
  struct pnode * next;
};
typedef struct pnode * LPTR;
LPTR create(string s, int i) {
  LPTR t = new pnode;
  if (s[i] == '*') {
    return NULL;
  } 
  else {
    t -> data = s[i] - '0';
    t -> next = create(s, i + 1);
    return t;
  }
}

void printlst(LPTR l) {
  LPTR t = l;
  if (t == NULL) return;
  else {
    cout << t - > data << " ";
    printlst(t - > next);
  }
}
int main() {

  string s;
  cin >> s;
  LPTR l = create(s, 0);
  printlst(l);
  cout << endl;
  return 0;
}
