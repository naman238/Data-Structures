#include <iostream>

using namespace std;
struct pnode {
  int data;
  struct pnode * next;
};
typedef struct pnode * LPTR;
LPTR head = NULL;
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
bool detectloop(LPTR & l) {
  if (l == NULL)
    return 1;
  LPTR fast = l - > next - > next;
  LPTR slow = l;
  while (fast - > next != NULL && fast - > next - > next != NULL && slow != fast) {
    fast = fast - > next - > next;
    slow = slow - > next;
  }
  if (fast == slow)
    return 1;
  else
    return 0;
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
  cout << detectloop(l);
  cout << endl;
  return 0;
}
