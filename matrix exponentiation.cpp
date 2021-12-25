const int SZ=2,M=1e9+7;
struct matrix{
    LL a[SZ][SZ];
    matrix(){
        for (int i=0;i<SZ;i++)for (int j=0;j<SZ;j++)a[i][j]=0;
    }
    matrix operator *(matrix other){
        matrix ret;
        for (int i=0;i<SZ;i++){
            for (int j=0;j<SZ;j++){
                for (int k=0;k<SZ;k++){
                    ret.a[i][k]=(ret.a[i][k]+a[i][j]*other.a[j][k])%M;
                }
            }
        }
        return ret;
    }
    matrix operator +(matrix other){
        matrix ret;
        for (int i=0;i<SZ;i++){
            for (int j=0;j<SZ;j++){
                ret.a[i][j]=(ret.a[i][j]+a[i][j]+other.a[i][j])%M;
            }
        }
        return ret;
    }
    matrix POW(int b){
        matrix res,a=(*this);
        for (int i=0;i<SZ;i++)res.a[i][i]=1;
        while (b){
            if (b&1)res=res*a;
            a=a*a;
            b/=2;
        }
        return res;
    }
};
