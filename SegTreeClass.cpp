
class SegTree{  // sum Segment Tree
    private:

        long *tree;
        int N;

        void build(){
            for(int i = N-1; i > 0; i--){
                tree[i] = tree[2*i] + tree[2*i+1];
            }
        }

    public:

        SegTree(int arr[], int n){
            tree = new long[2*n];
            for(int i = 0; i < n; i++)tree[n+i] = arr[i];
            N = n;
            build();
        }

        long query(int l, int r){
            l += N;
            r += N;

            long ret = 0;

            while(l <= r){
                if(l&1)ret += tree[l++];
                if(!(r&1))ret += tree[r--];
                l >>= 1;
                r >>= 1;
            }

            return ret;
        }

        void pointUpdate(int pos, int val){
            pos += N;
            while(pos ){
                tree[pos] += val;
                pos >>= 1;
            }
        }

};
