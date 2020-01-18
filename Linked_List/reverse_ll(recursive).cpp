#include <iostream>

using namespace std;
struct pnode {
  int data;
  struct pnode * next;
};
typedef struct pnode * LPTR;
LPTR head = NULL;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct pnode * create(int x) {
  LPTR p;
  p = new(struct pnode);
  p - > next = NULL;
  p - > data = x;
  return p;
}
void add(LPTR & l, int x) {
  if (l == NULL) {
    l = create(x);
    head = l;
  } else {
    LPTR temp = l;
    while (temp - > next != NULL) {
      temp = temp - > next;
    }
    temp - > next = create(x);
  }
}
void rev(LPTR l) {
  if (l - > next == NULL) {
    head = l;
    return;
  }
  rev(l - > next);
  LPTR q = l - > next;
  q - > next = l;
  l - > next = NULL;
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
  LPTR l = NULL;
  add(l, 2);
  add(l, 3);
  add(l, 5);
  add(l, 8);
  add(l, 32);
  rev(l);
  printlst(head);

  cout << endl;
  return 0;
}
