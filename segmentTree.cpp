struct node{
  int  ans;
  node(){
    ans=0;
  }
}t[4*N];
node merge(node a, node b){
   node res;
   res.ans=a.ans+b.ans;
   return res;
}
void update(int ind, int lx , int rx, int pos, int val){
  if(lx==rx){
    t[ind].ans=val;
    return;
  }
  int mid=(lx+rx)/2;
  if(pos <= mid){
    update(ind << 1, lx, mid, pos, val);
  }
  else{
    update(ind << 1 | 1, mid+1, rx, pos, val);
  }
  t[ind]=merge(t[ind << 1], t[ind << 1 | 1]);
}
node query(int ind, int lx, int rx, int l, int r){
  if(lx > r || rx < l){
    return node();
  }
  if(lx >= l && rx <= r){
    return t[ind];
  }
  int mid=(lx+rx)>>1;
  return merge(query(ind << 1, lx, mid, l, r),query(ind << 1 | 1, mid+1, rx, l, r));
}