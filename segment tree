struct ST{
    int t[4*N];
    ST(){
        memset(t,0,sizeof t);
    }
    int combine(int x,int y){
        return x+y;
    }
    void build(int v,int tl,int tr){
        if (tl==tr){
            t[v]=a[tl];
        }
        else {
            int tm=(tl+tr)/2;
            build(v*2,tl,tm);
            build(v*2+1,tm+1,tr);
            t[v]=combine(t[v*2],t[v*2+1]);
        }
    }
    void _update(int v,int tl,int tr,int pos,int val){
        if (tl==tr){
            t[v]=val;
        }
        else {
            int tm=(tl+tr)/2;
            if (pos<=tm)_update(v*2,tl,tm,pos,val);
            else _update(v*2+1,tm+1,tr,pos,val);
            t[v]=combine(t[v*2],t[v*2+1]);
        }
    }
    void update(int pos,int val){
        _update(1,0,n-1,pos,val);
    }
    int _get(int v,int tl,int tr,int l,int r){
        if (tl>r||tr<l)return 0;
        if (tl>=l&&tr<=r)return t[v];
        int tm=(tl+tr)/2;
        int L=_get(v*2,tl,tm,l,r);
        int R=_get(v*2+1,tm+1,tr,l,r);
        return combine(L,R);
    }
    int get(int l,int r){
        return _get(1,0,n-1,l,r);
    }
};
