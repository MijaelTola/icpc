#include <bits/stdc++.h>

using namespace std;

struct node {
  int val,head,tail;
  node *left, *right;
  node () {head = 0, tail = 0;}
  node (node *l, node *r, int _) {
    left = l;
    right = r;
    val = _;
    head = 0, tail = 0;
  }
};

void build(node *n, int l, int r) {
	if(l == r) {
    n->val = -1;
  	return;
  }
  int mid = (l + r) / 2;
  n->left = new node(NULL, NULL, 0);
  n->right = new node(NULL, NULL, 0);
  build(n->left,l, mid);
  build(n->right,mid + 1, r);
}

void push(node *last, node *cur, int l, int r, int pos, int x) {
  if(l == r) {
    cur->val = x;
  	return;
  }
  int mid = (l + r) / 2;
  if(pos <= mid) {
    cur->right = last->right;
    cur->left = new node(NULL, NULL, 0);
    push(last->left, cur->left, l, mid, pos, x);
  } else {
  	cur->left = last->left;
    cur->right = new node(NULL, NULL, 0);
    push(last->right, cur->right, mid + 1, r, pos, x);
  }
}

int pop(node *n, node *cur, int l, int r, int pos) {
  if(l == r) {
    return n->val;
  }
  int mid = (l + r) / 2;
  if(pos <= mid) {
    cur->right = n->right;
    cur->left = n->left;
    return pop(n->left, cur->left, l, mid, pos);
  } else {
  	cur->left = n->left;
    cur->right = n->right;
    return pop(n->right, cur->right, mid + 1, r, pos);
  }
}

vector<node*> version;

const int lim = 200010;
int main (){
  ios::sync_with_stdio(false); cin.tie(0);
  node* Queue = new node(NULL,NULL,0);
  build(Queue,0, lim);
  version.push_back(Queue);

  int t;
  cin >> t;
  
  while(t--) {
  	int p,x,v;
    cin >> p;
    if(p == 1) {
      cin >> v >> x;
      int tail = version[v]->tail;
      int head = version[v]->head;
      node * nqueue = new node(NULL, NULL, 0);

      nqueue->head = head;
      nqueue->tail = (tail + 1) % lim;

      push(version[v], nqueue, 0, lim, tail, x);
      version.push_back(nqueue);
    } else {
      cin >> v;

      int head = version[v]->head;
      int tail = version[v]->tail;
      node *nqueue = new node(NULL, NULL, 0);

      int ans = pop(version[v], nqueue, 0, lim, head);

      nqueue->tail = tail;
      nqueue->head = (head + 1) % lim;
      version.push_back(nqueue);

      cout << ans << "\n";
    }
  }
  return 0;
}
