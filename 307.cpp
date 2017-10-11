class NumArray {
public:
    NumArray(vector<int> nums) {
        memset(bit,0,sizeof(bit));
        num=nums;
        n=nums.size();
        for(long long i=0;i<n;i++)
        {
            init(i,num[i]);
        }
    }
    
    void init(long long i,long long val)
    {
        i++;
        while(i<=n)
        {
            bit[i]+=val;
            i+=(i&-i);
        }
    }
    
    void update(long long i, long long val) {
        long long diff=val-num[i];
        num[i]=val;
        init(i,diff);
    }
    
    long long getsum(long long i)
    {
        long long sum=0;
        i++;
        while(i>0)
        {
            sum+=bit[i];
            i-=(i&-i);
        }
        return sum;
    }
    
    int sumRange(long long i, long long j) {
        return getsum(j)-getsum(i-1);
    }
private:
    vector<int> num;
    long long bit[200000];
    int n;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
