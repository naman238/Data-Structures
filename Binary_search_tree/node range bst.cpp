#include <iostream>

using namespace std;
struct bstnode {
  bstnode * lc;
  int data;
  bstnode * rc;
};
typedef bstnode * Bstptr;
void insert(Bstptr & T, int x) {
  if (T == NULL) {
    Bstptr l = new bstnode;
    l - > data = x;
    l - > lc = l - > rc = NULL;
    T = l;
  } else {
    if (T - > data < x) {
      insert(T - > rc, x);
    } else {
      insert(T - > lc, x);
    }
  }
}
void inorder(Bstptr T) {
  if (T != NULL) {
    inorder(T - > lc);
    cout << T - > data << " ";
    inorder(T - > rc);
  }
}
int findmin(Bstptr T) {
  if (T == NULL) {
    return -1;
  } else if (T - > lc == NULL) {
    return T - > data;
  } else {
    return findmin(T - > lc);
  }
}
int findmax(Bstptr T) {
  if (T == NULL)
    return -1;
  else if (T - > rc == NULL)
    return T - > data;
  else
    return findmax(T - > rc);
}
void findrange(Bstptr T, int x) {
  static int ll = INT_MIN;
  static int ul = INT_MAX;
  if (T == NULL)
    return;
  else if (T - > data < x) {
    ll = T - > data + 1;
    findrange(T - > rc, x);
  } else if (T - > data > x) {
    ul = T - > data - 1;
    findrange(T - > lc, x);
  } else {
    if (T - > lc != NULL) {
      ll = findmax(T - > lc) + 1;
    }
    if (T - > rc != NULL) {
      ul = findmin(T - > rc) - 1;
    }
    cout << ll << " " << ul;
  }
}
int main() {
  int n;
  cin >> n;
  Bstptr T = NULL;
  int x;
  for (int i = 0; i < n; i++) {
    cin >> x;
    insert(T, x);
  }
  cout << "inorder: ";
  inorder(T);
  cout << endl;
  cout << "enter element whose range u want to find: ";
  cin >> x;
  findrange(T, x);
  return 0;
}
