#include <iostream>

using namespace std;
struct pnode {
  int data;
  struct pnode * next1;
  struct pnode * next2; 	//can be done with two in an efficent way
};
typedef struct pnode * LPTR;
struct pnode * create(int x) {
  LPTR p;
  p = new(struct pnode);
  p - > next1 = NULL;
  p - > next2 = NULL;
  p - > data = x;
  return p;
}
void add(LPTR & l, int x) {
  LPTR temp = l;
  while (temp - > next1 != NULL) {
    temp = temp - > next1;
  }
  temp - > next1 = create(x);
}
int delt(LPTR & l) {
  LPTR t = l - > next1;
  if (t != NULL) {
    int x = t - > data;
    if (t - > next1 != NULL)
      l - > next1 = t - > next1;
    else
      l - > next1 = NULL;
    return x;
  }
  return -1;
}
void func(LPTR & l, int a[], int n) {
  LPTR temp = l;
  for (int i = 0; i < n;) {
    while (temp - > next1 != NULL) {
      a[i] = delt(temp);
      i++;
    }
    temp = temp - > next2;
  }

}

int main() {
  LPTR l = NULL;

  l = create(0);
  LPTR temp = l;
  for (int i = 1; i < 10; i++) {

    temp - > next2 = create(i);
    temp = temp - > next2;
    if (i == 9) {
      temp - > next2 = NULL;
    }
  }
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];

  for (int i = 0; i < n; i++) {
    LPTR t = l;
    int x = a[i] % 10;

    while (t - > data != x && t - > next2 != NULL) {
      t = t - > next2;
    }
    add(t, a[i]);

  }
  func(l, a, n);
  for (int i = 0; i < n; i++) {
    LPTR t1 = l;
    int x = (a[i] % 100) / 10;
    while (t1 - > data != x && t1 - > next2 != NULL)
      t1 = t1 - > next2;
    add(t1, a[i]);
  }
  func(l, a, n);
  for (int i = 0; i < n; i++) {
    LPTR t2 = l;
    int x = a[i] / 100;
    while (t2 - > data != x && t2 - > next2 != NULL)
      t2 = t2 - > next2;
    add(t2, a[i]);
  }
  func(l, a, n);
  for (int i = 0; i < n; i++)
    cout << a[i] << " ";
  cout << endl;
  return 0;
}
