#include<iostream> 
#include<unordered_map>
#include<map>
#include<set>
#include<unordered_set>

// unordered maps uses hash tables and does all the function in o(1)
// ordered maps uses BST and does all the functions in o(n). 


using namespace std; 

template<typename v>
class mapNode{
    public:
    string key; 
    v value ; 
    mapNode* next; 

    mapNode(string key, v value)
    {
        this->key= key ; 
        this->value= value ; 
        next = NULL; 
         
    }
    ~mapNode()
    {
        delete next; 
    }


};

// we need a class of maps too  which will contain the map nodes 
template<typename v> 
class mymap
{
    mapNode<v>** buckets; 
    int count; 
    int numBuckets ; 



    int getbucketindex(string key) // hash function and compression function together 
    {
        // number with base p methode  // let's take p = 37 ; 
        int hashcode = 0 ; 
        int base = 1; 
        int p = 37  ;

        for(int i = key.size()-1; i>= 0 ; i++)
        {
           hashcode+= (key[i]*base);
           base=(base*p);
           // but base and hascode is increasing at very much rate so we use mod property [n1*n2*n3]%r= [(n1*%r)*(n2%r)*(n3%r)]%r;
           hashcode=hashcode%numBuckets;
           base=base%numBuckets;
        }

        return hashcode%numBuckets; 

    }

    // rehashing function 

    void rehash()
    {
        mapNode<v>** temp= buckets; 
        buckets = new mapNode<v>*[2*numBuckets] ; 
        for(int i = 0; i<2*numBuckets; i++)
        {
            buckets[i] = NULL; 
             
        }
        int oldBucketSize= numBuckets; 
        numBuckets*= 2; 
        count= 0 ; 
        for(int i = 0 ; i< oldBucketSize; i++) 
        {
            mapNode<v> * head = temp[i];
            while(head!=NULL)
            {
                string key = head->key; 
                v value = head->value; 
                insert(key,value); // insert function inserts in the buckets array so it will be stored in the new buckets; 


                head=head->next; 
                
            }
        }
        for(int i = 0 ; i<oldBucketSize;i++)
        {
            delete temp[i];
        }
        delete []temp; 

    }

    mymap()
    {
        count = 0 ;
        numBuckets = 5; 
        buckets = new mapNode<v>*[numBuckets]; 
        for(int i = 0 ; i< numBuckets ; i++) 
        {
            buckets[i] = 0 ; 

        }

    }
    ~mymap()
    {
        for(int i = 0 ; i<numBuckets; i++) 
        {
            delete bucket[i]; 
        }
        delete []buckets; 

    }

    public: 
    // size function ; 

    int size()
    {
        return count ; 
    }

    v getValue(string key)
    {
        int bucketindex= getbucketindex(key);
        mapNode<v> * head = buckets[bucketindex];
        while(head!=NULL)
        {
            if(head->key= key )
            {
                return head->value; 

            }
            head = head->next; 

        }
        return 0 ; 
    }

    void insert(string key, v value)
    {
        int bucketindex = getbucketindex(key); 
        mapNode<v> * head= buckets[bucketindex]; 
        while(head!=NULL)
        {
            if(head->key== key)
            { 
                head->value= value ;
                return ; 
            }
            head= head->next; 
        }
        mapNode<v>* n = new mapNode<v>(key,value);
        n->next= buckets[bucketindex];  
        buckets[bucketindex] = n ;  m 
        count ++;
        // rehashing 

        double loadFactor= (1.0*count)/numBuckets; 
        if (loadFactor> 0.7)
        { 
            rehash();
        }
    }

    void remove(string key )
    {
        int bucketindex= getbucketindex(key); 
        mapNode<v>* head = buckets[bucketindex] ; 
        mapNode<v> * pre = NULL ;
        while(!= NULL)
        {
            if (head->key= key )
            {
                if (prev== NULL) 
                {
                    buckets[bucketindex] = head->next; 
                }
                else
                {
                    pre->next= head->next; 
                }
                head->next=NULL;
                delete head; 
                count -- ;  

            }
            pre= head; 
            head= head->next; 
        }
    }



};

// using maps we will create a function that removes all the duplicates from the array .
vector<int> remDup( vector<int> v)
{
    vector<int> ans; 
    unordered_map<int,bool> mymaps; 

    for( int i= 0; i< v.size(); i++)
    {
        
        if(mymaps.count(v[i]) == 0 )
        {
            ans.push_back(v[i]); 
            mymaps[v[i]] = true ; 
        }
    }
    return ans ; 

}

int main()
{
    unordered_map<string,int> mymaps ; 
    // there are two ways to insert 1; using a pair , 2; using array method ; 
    pair<string,int> p; 
    p.first= "abs" ; 
    p.second = 10; 
    mymaps.insert(p); 

    mymaps["def"] = 22 ; 

    // find or access
    cout<<mymaps["def"]<<endl;  // it will create the word and then give it value of zero. 
    cout<<mymaps.at("def")<<endl;  // it will show error if the given zero key is not present ;

    // count function 
    // it will give how many times a key is present and since the key is unique so it has only 2 outputs 1 and 0 ; 

    cout<<mymaps.count("def")<<endl; 
    
    // update 

    mymaps["abs"] = 43 ; 

    cout<<mymaps["abs"]<<endl; 
    
    // erase 

    mymaps.erase("def");
    cout<<mymaps.count("def");

    // let's see iterators 

    // first let's see for unordered maps 

    unordered_map<string,int> mymaps_1; 
    mymaps_1["abc"] = 2; 
    mymaps_1["abc1"] = 3 ; 
    mymaps_1["abc2"] = 1; 
    mymaps_1["abc3"] = 10 ; 

    for( unordered_map<string,int> :: iterator it = mymaps_1.begin() ; it != mymaps_1.end(); it++)
    {
        cout<<"key : "<<it->first<<" value : "<< it->second<<endl; 
    }

    // this is unordered. 


    map<string,int> mymaps_2 ; 

    mymaps_2["abc"] = 10; 
    mymaps_2["abc1"] = 2 ; 
    mymaps_2["abc2"] = 3 ; 
    mymaps_2["abc3"] = 4 ; 

    for( map<string,int> :: iterator it  = mymaps_2.begin(); it != mymaps_2.end(); it++)
    {
        cout<<"key : "<<it->first<<" value : "<<it->second<<endl; 

    }
    // this is ordered wrt to the key .

    for(const auto &it : mymaps_1)
    {
        
    }

    set<int> s; 
    s.insert(5);
    s.insert(4);

    for(const auto& i: s) // const auto& is used so to make sure it;s not a copy of 
                        // the variable rather a reference.
    {
        cout<<i<<" ";
    }

}
