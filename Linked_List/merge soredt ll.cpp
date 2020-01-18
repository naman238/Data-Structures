#include <bits/stdc++.h>

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
LPTR mergesort(LPTR & l, LPTR & l2) 
{
  LPTR t = l2;
  LPTR p = l;
  LPTR prevp = p;
  LPTR prevt = t;
  while (p != NULL && t != NULL) 
  {
    if (p - > data <= t - > data) {
      prevp = p;
      p = p - > next;
    } 
	else {
      prevt = t;
      prevp - > next = t;
      while (t != NULL && t - > data < p - > data) {
        prevt = t;
        t = t - > next;
      }
      prevt - > next = p;
    }
  }
  if (t - > next == NULL) 
  {
    prevt - > next = p;
  } 
  else 
  {
    prevp - > next = t;
  }
  return l;
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
  add(l, 1);
  add(l, 3);
  add(l, 5);
  add(l, 10);
  add(l, 12);
  LPTR l2 = NULL;
  add(l2, 4);
  add(l2, 7);
  add(l2, 8);
  add(l2, 9);
  add(l2, 11);
  add(l2, 12);
  add(l2, 14);
  LPTR l1 = mergesort(l, l2);
  printlst(l1);
  cout << endl;
  return 0;
}
