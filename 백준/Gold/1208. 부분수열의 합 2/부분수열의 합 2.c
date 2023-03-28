long k[8000001];
int n,s,i,j,a;
int main()
{
    scanf("%d%d",&n,&s);
    for(i=0;i<n;i++)
        {
            scanf("%d",&a);
            if(a<0)
                for(j=-a;j<=8000000;j++)k[a+j]+=k[j];
            else 
                for(j=8000000-a;j>=0;j--)k[a+j]+=k[j];
            k[a+4000000]++;
        }
    printf("%lld\n",k[s+4000000]);
}