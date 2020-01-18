#include <iostream>

using namespace std;
struct pnode {
  int data;
  struct pnode * next;
};
typedef struct pnode * LPTR;

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
  } else {
    LPTR temp = l;
    while (temp - > next != NULL) {
      temp = temp - > next;
    }
    temp - > next = create(x);
  }
}

void rev(LPTR & l) {
  LPTR curr = l;
  LPTR prev = NULL;
  LPTR n = curr - > next;
  while (curr - > next != NULL) {
    curr - > next = prev;
    prev = curr;
    curr = n;
    n = curr - > next;
  }
  curr - > next = prev;
  l = curr;
}

void printlst(LPTR & l) {
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
  printlst(l);
  cout << endl;
  return 0;
}
