#include <iostream>
using namespace std;
struct pnode {
  int data;
  struct pnode * next;
};
typedef struct pnode * LPTR;
struct pnode * create(int x) {
  LPTR p;
  p = new(struct pnode);
  p -> next = NULL;
  p -> data = x;
  return p;
}
void add(LPTR & l, int x) {
  if (l == NULL) {
    l = create(x);

  } else {
    LPTR temp = l;
    while (temp -> next != NULL) {
      temp = temp -> next;
    }
    temp -> next = create(x);
  }
}
int delt(LPTR & l) {
  LPTR t = l;
  int x;
  if (t != NULL) {
    x = t -> data;
    l = l -> next;
    delete t;
  }
  return x;
}
void func(LPTR l[], int a[], int n) {
  int j = 0;
  for (int i = 0; i < n;) {

    while (l[j] != NULL) {
      a[i] = delt(l[j]);
      i++;
    }
    j++;
  }
}
int main() {
  LPTR l[10];
  for (int i = 0; i < 10; i++) {
    l[i] = NULL;
  }
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++) {
    int x = a[i] % 10;
    add(l[x], a[i]);
  }
  func(l, a, n);
  for (int i = 0; i < n; i++) {
    int x = (a[i] % 100) / 10;
    add(l[x], a[i]);
  }
  func(l, a, n);
  for (int i = 0; i < n; i++) {
    int x = a[i] / 100;
    add(l[x], a[i]);
  }
  func(l, a, n);
  for (int i = 0; i < n; i++)
    cout << a[i] << " ";
  cout << endl;
  return 0;
}
