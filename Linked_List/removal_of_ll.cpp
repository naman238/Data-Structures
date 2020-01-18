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

void mid(LPTR & l) {
  LPTR fast = l;
  LPTR slow = l;
  if (l == NULL)
    return;
  while (fast - > next != NULL && fast - > next - > next != NULL) {
    fast = fast - > next - > next;
    slow = slow - > next;
  }
  cout << slow - > data;

}
LPTR detectloop(LPTR & l) {

  LPTR fast = l - > next - > next;
  LPTR slow = l - > next;
  while (fast - > next != NULL && fast - > next - > next != NULL && slow != fast) {
    fast = fast - > next - > next;
    slow = slow - > next;
  }
  if (fast == slow)
    return slow;
  else
    return NULL;
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
  add(l, 45);
  add(l, 50);
  add(l, 12);
  LPTR temp = l;
  while (temp - > next != NULL) {
    temp = temp - > next;
  }
  LPTR temp1 = l;
  temp1 = temp1 - > next - > next;
  temp - > next = temp1;
  LPTR x = detectloop(l);
  temp1 = l;
  while (x != temp) {
    x = x - > next;
    temp1 = temp1 - > next;
  }
  LPTR y = x;
  while (y != x) {
    y = y - > next;
  }
  y - > next = NULL;
  printlst(l);
  cout << endl;
  return 0;
}
