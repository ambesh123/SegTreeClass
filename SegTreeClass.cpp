
/*
Generic Segment Tree

Just Change 2 things according to requirement:
1. combine function ( a+b for sum segment tree, max(a,b) for RMQ query etc.)
2. ZERO value  (The value which you consider zero for combine function eg. INT_MAX for Min RMQ segment Tree and 0 for Sum Segment Tree)

    -- Author : Ambesh Tiwari
*/

template<typename T>
class SegTree{  //generic segment Tree
    private:

        T *tree;
        int N;
        int ZERO; // Zero value for query

        T combine(T x, T y){    //define the combine function here
            return max(x,y);
        }

        void build(){
            for(int i = N-1; i > 0; i--){
                tree[i] = combine(tree[i<<1] , tree[i<<1|1]);
            }
        }

    public:

        SegTree(T arr[], int n){
            ZERO = 0; // define zero value here
            tree = new T[2*n];
            for(int i = 0; i < n; i++)tree[n+i] = arr[i];
            N = n;
            build();
        }

        T query(int l, int r){
            
            if(r < l) return ZERO;

            l += N;
            r += N;

            T ret = ZERO;

            while(l <= r){
                if(l&1)ret = combine(ret, tree[l++]);
                if(!(r&1))ret = combine(ret, tree[r--]);
                l >>= 1;
                r >>= 1;
            }

            return ret;
        }

        void pointUpdate(int pos, T val){
            pos += N;
            tree[pos] = val;
            while(pos > 1){
                pos >>= 1;
                tree[pos] = combine(tree[pos<<1], tree[pos<<1|1]);
            }
        }

};
