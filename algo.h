
#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using di=deque<int>;
using si = set<int>;
using vs = vector<string>;
using vvs = vector<vs>;
using vd = vector<double>;


using ull = unsigned long long;
using ll=long long;
using pii = pair<int,int>;
using vpii = vector<pair<int,int>>;
using pcc = pair<char, char>;
using tri = tuple<int, int, int>;
using pq = priority_queue<int, vector<int>, less<int>>;
using bits=bitset<50>;

#define mp(x, y) make_pair(x, y)
#define mt(x, y, z) mp(mp(x,y),z)

#define x(p) (p).first
#define y(p) (p).second

#define tx(t) (t).first.first
#define ty(t) (t).first.second
#define tz(t) (t).second


#define va(v) (v).begin(), (v).end()
#define dbg_vi(v) do { copy(va(v),ostream_iterator<int>(cout,"\t")); cout << endl; } while(0)
#define dbg_vs(v) do { copy(va(v),ostream_iterator<string>(cout,"\n")); cout << endl; } while(0)
#define dbg_vd(v) do { copy(va(v),ostream_iterator<double>(cout,"\t")); cout << endl; } while(0)=

#define dbg_vpii(v) do { copy(va(v), ostream_iterator<pii>(cout,"\n")); cout << endl; } while(0)


#define fe(v,it) for(__typeof(v.begin()) it=v.begin(); it != v.end(); it++)
 
#define bz(a) memset(a,0,sizeof(a))
#define sq(x) ((x)*(x))
#define fi(a, b) for(int i=((int)(a)); i < ((int)(b)); i++)
#define fj(a, b) for(int j=((int)(a)); j < ((int)(b)); j++)
#define fk(a, b) for(int k=((int)(a)); k < ((int)(b)); k++)
#define fie(a, b) for(int i=((int)(a)); i <= ((int)(b)); i++)
#define fje(a, b) for(int j=((int)(a)); j <= ((int)(b)); j++)
#define fke(a, b) for(int k=((int)(a)); k <= ((int)(b)); k++)
#define isin(a, aset) (aset.count((a))>0)
#define notin(a, aset) (!aset.count((a))>0)
#define a2z(v)            (v).begin(),(v).end()


typedef vi::iterator  itri;
typedef vs::iterator  itrs;
typedef vd::iterator  itrd;

#define ffof   find_first_of
#define ffnof  find_first_not_of

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)>(b)?(b):(a))
#define ABS(a)   MAX((a),-(a))
#define DIST(a,b) ABS((a)-(b))

#define vpb(v,a) (v).push_back(a)
#define vpf(v,a) (v).push_front(a)
#define vpob(v) (v).pop_back()
#define vpof(v) (v).pop_front()

#define vf(v,a) find(va(v),(a))
#define ve(v,a) (vf(v,a)!=(v).end())
#define vins(v,a) do { if (!ve(v,a)) vpb(v, a); } while(0)
#define vind(v,a) (ve(v,a)?(vf(v,a)-v.begin()):-1)
#define vdel(v,a) v.erase(remove(va(v),a),v.end())

#define len(v) (v).size()


////////////////////
// handy printing
///////////////////////
namespace std
{
  std::ostream& operator<<(std::ostream& strm,
                           const std::pair<int,int>& kvPair)
    {
      strm << "(" << kvPair.first << "," << kvPair.second << ")";
      return strm;
    }
}


template <class T>
void printv(vector<T> v)
{
  copy(a2z(v),ostream_iterator<T>(cout,","));
}

template <class T>
void printd(deque<T> v)
{
  copy(a2z(v),ostream_iterator<T>(cout,","));
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const std::set<T>& set)
{
    if (set.empty())
        return out << "{}";
    out << "{ " << *set.begin();
    std::for_each(std::next(set.begin()), set.end(), [&out](const T& element)
    {
        out << ", " << element;
    });
    return out << " }";
}

//void print_map(const std::map<vert, vector<vert>>& m)
template<typename T>
std::ostream& operator<<(std::ostream& out, const std::map<T, vector<T>>& m)

{
    // Iterate using C++17 facilities
    for (const auto& [key, value] : m){
     out << '[' << key << "] = ";
     for(auto vv: value) out << vv << ", ";
     out << std::endl;
    }
 
// C++11 alternative:
//  for (const auto& n : m)
//      std::cout << n.first << " = " << n.second << "; ";
//
// C++98 alternative:
//  for (std::map<std::string, int>::const_iterator it = m.begin(); it != m.end(); ++it)
//      std::cout << it->first << " = " << it->second << "; ";
 
    out << '\n';
    return out;
}


//////////////////////////////////////////////
// disjoint union. great of finding cc of an image and min spanning sets
//////////////////////////////////////////////////////////////

    map<pii, pii> parent;

//make sure you initialize this with everything in your set
    void make_set(pii v) {
        parent[v] = v;
    }

    //this feature has path compression 
    pii find_set(pii v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

//this particular union set choose the parent that is the
//smallest in dictionary ordering. theres many other ways to go here
//especially to optimize for size & rank.
    void union_sets(pii a, pii b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if(a.first==b.first){
                if(a.second<b.second) parent[b]=a;
                else parent[a]=b;
            }
            else {
                if(a.first<b.first) parent[b] = a;
                else parent[a]=b;
            }

        }
    }



///////////////////////////////////////////////////////
// extending priority_queue to implement 'remove'
// super useful in two heaps type problems
////////////////////////////////////////////////////
template <typename T, class Container = vector<T>,
          class Compare = less<typename Container::value_type>>
class priority_queue_with_remove : public priority_queue<T, Container, Compare> {
 public:
  bool remove(const T &valueToRemove) {
    auto itr = std::find(this->c.begin(), this->c.end(), valueToRemove);
    if (itr == this->c.end()) {
      return false;
    }
    this->c.erase(itr);
    // ideally we should not be rebuilding the heap as we are removing only one element
    // a custom implementation of priority queue can adjust only one element in O(logN)
    std::make_heap(this->c.begin(), this->c.end(), this->comp);
    return true;
  }
};

//and here is a comparator example
struct lttype
{
    bool operator()(const tri & p1, const tri & p2)
    {
        return false;

    }
};



//__builtin_ctz (count trailing zeros of an unsigned int) warning: undefined for 0.
//__builtin_clz (count leading zeros of an unsigned int) warning: undefined for 0.
//__builtin_popcount (count number of 1s in an unsigned int)
//__builtin_ctzll (count trailing zeros of an an unsigned ll) warning: undefined for 0.
//__builtin_clzll (count leading zeros of an unsigned ll) warning: undefined for 0.
//__builtin_popcountll (count number of 1s in an unsigned ll)



//#define fi(a, b) for (int i = ((int)(a)); i < ((int)(b)); i++)
//#define fj(a, b) for (int j = ((int)(a)); j < ((int)(b)); j++)
//#define fk(a, b) for (int k = ((int)(a)); k < ((int)(b)); k++)
//#define fori(a) for (int i = ((int)(0)); i < ((int)(a.size())); i++)
//#define forj(a) for (int j = ((int)(0)); j < ((int)(a.size())); j++)





typedef long long ll;
typedef unsigned long long ull;

inline ll gcd(ll a, ll b) { if (b==0) return a; return gcd(b, a%b); }
inline ll lcm(ll a, ll b) { return (a*b)/gcd(a,b);                  }
inline ull factorial(ull n) {
  return (n==0)? 1 : n * factorial(n-1); 
}
inline int gethighestpower(ll prime, ll number)
{
  int ret(0);
  while((number % prime)==0){
    ret++;
    number = number/prime;
  }
  return ret;
}



vector<uint64_t>   masks(64,0), steps(64,0);

void prep()
{
  fi(0,masks.size()) masks[i] = 1LL << i; //masks[0]=1;
  fi(1,64) steps[64-i-1]=0xFFFFFFFFFFFFFFFFLL >> i; //these are step functions. steps[0]=1;
}

struct ltstr
{
  bool operator()(const char* s1, const char* s2) const
  {
    return strcmp(s1, s2) < 0;
  }
};



////////////////////////////////////////////
// code snippets
////////////////////////////////////////////
//summing vectors
//int sum = accumulate(all(v),0);
//long long sum = accumulate(all(v),(long long)0);

//calc product
//double product = accumulate(all(v), double(1), multiplies<double>()); 

//calc inner product!
//int r = inner_product(all(v1), v2.begin(), 0); 

//number of ways of putting n things in k bins is:
// 
//  nchoosek(n+k-1,k-1) = nchoosek(n+k-1,n)
//

ull nchoosek(int n, int k)
{
  if(k==0) return 1LL;
  if(n==0) return 0LL;

  vector<ull>  nk(n+1,0);
  nk[0]=1LL;
  for(int i=1; i<=n; i++) for(int j=i;j>=1;j--) nk[j] += nk[j-1];

  return nk[k];
}



void permutation(vi nums)
{
  sort(nums.begin(), nums.end());
 
  while(next_permutation(nums.begin(),nums.end()))
    {
      dbg_vi(nums);
    }
}

//k partitions of n
//the number of k partitions of n is p(k,n), which is the 
//nmber of ways of expressing k positive integers whose sum is n. 
//basically: use this recursion:
// p(k,n)=0 if k>n
// p(k,n)=1 if k==n
// p(k,n) = p(k+1,n)+p(k,n-k)


//combination on a vi. 
//this is about finding all subsets of size nunums.size() of nums, where order does not matter
//in this version, you can have repeated numbers in nums.
//nums: the collection of numbers you want
//nunums.size(): size subsets of
//occ: is occupancy. should be init'd to 0. is buffer used internally, only.
// and nums.size() < 64. assuming nunums.size() <= nums.size().
void combination_reps(vi & nums, uint64_t occ, vi nunums)
{
  int idx(0);
  int num1s(__builtin_popcountll(occ));
  if(occ == 0) sort(nums.begin(),nums.end());
  else
    {
      if(num1s == nunums.size())
        {
          //do something
          dbg_vi(nunums);
          return;
        }
  
      idx = 64-__builtin_clzll(occ); 
    }

  if(idx <= nums.size()-num1s+1)
    {
      nunums[num1s]=nums[idx];
      combination_reps(nums,(occ | ( 1LL << idx)),nunums);

      fi(idx+1,nums.size())
        {
          if((((1LL << i) & occ) == 0) && (nums[i] != nums[i-1]))
            {
              nunums[num1s]=nums[i];
              combination_reps(nums,(occ | ( 1LL << i)),nunums);
            }
        }
    }
}


//combination on a vi. 
//this is about finding all subsets of size nunums.size() of nums, where order does not matter
//in this version, you cannot have repeated numbers in nums.
//nums: the collection of numbers you want
//nunums.size(): size subsets of
//occ: is occupancy. should be init'd to 0. is buffer used internally, only.
// and nums.size() < 64. assuming nunums.size() <= nums.size().
void combination_noreps(const vi &  nums, uint64_t occ, vi nunums)
{

  if(__builtin_popcountll(occ) == nunums.size())
    {
      //do something
      return;
    }

  int idx(0);
  if(occ) idx = 64-__builtin_clzll(occ); 

  fi(idx,nums.size())
    {
      if(((1LL << i) & occ) == 0)
        {
          nunums[__builtin_popcountll(occ)]=nums[i];
          combination_noreps(nums,(occ | (1LL << i)),nunums);
        }
    }
}

//combination on a set of integers, indexed by a mask 
//this is about finding all distinct subsets of size subset_size of nums, where order does not matter
//nums: the collection of numbers, indexed by bit
//nunums.size(): size subsets of
//occ: is occupancy. should be init'd to 0. is buffer used internally, only.
//pos: is positions. should be init'd to 0. is used internally.
// and subset_size < 64. assuming nunums.size() <= nums.size().
//tot_num: is returned. is the total number of subsets of that sz
void combination_noreps(const uint64_t &  nums, int subset_size,uint64_t occ,  int pos, int & tot_num)
{
  if(__builtin_popcountll(occ) == subset_size)
    {
      //here, you can do something useful.
      //for example, if you wanted to find k partitions of n things where you can have a 0 partition,
      //pick k-1 subsets of n+k-1 numbers, and use the chosen numbers as partitions, where
      //if you pick 0, that means that first partition has size 0
      tot_num++;
      return;
    }

  fi(__builtin_ctzll(nums)+pos,64-__builtin_clzll(nums))
    {
      uint64_t bit = (1LL << i);
      if((bit & occ) == 0 && (bit & nums) > 1)
        combination_noreps(nums,subset_size, (occ | bit),i-__builtin_ctzll(nums)+1,tot_num);
    }

}

//the following is variant on the above
bool next(const uint64_t & nums, int subset_size, uint64_t & occ, int & pos)
{
  if(pos >= 64-__builtin_clzll(nums) - __builtin_ctzll(nums)) return false;
  uint64_t bit = (1LL << (pos+__builtin_ctzll(nums)));
  pos = pos+1;
  if((bit & occ) == 0 && (bit & nums) > 1)
    {
      occ = occ | bit;
      return true; 
    }
  return next(nums, subset_size, occ, pos);
}

//this generates the partitions of n
//i.e., k nonnegative numbers whose sum is n
//k = partition.size()
//pos is initialized to 0, and is used internally
//sum is initialized to 0, and is used internally
void partitions(int n, vi partition, int pos, int sum)
{
  
  if(pos==(partition.size()-1))
    {
      partition[pos]=n-sum;
    
      //do something
      dbg_vi(partition);
      return;
    }

  for(int i=0; i<= n-sum; i++)
    {
      partition[pos]=i;
      partitions(n, partition, pos+1,sum+i);
    }
}


template<typename T>
class primer
{
public:

  primer(int maxn=10000): maxval(maxn)
  {
    SPF.resize(maxval);
    sieve(maxval);
  }
  
  const T maxval;

  vector<T> SPF;
  vector<T> primes;

  // make sure that MAX is at least sqrt n
  // populated primes with all primes less than n
  void sieve(T n) {
    vector<bool> isPrime(n+1, true);
    isPrime[1] = false;
    for (T i=2; i<=n; i++) {
      // assert isPrime == True
      if (!isPrime[i]) continue;
      /* j*(i-1) has a factor of (i-1) and was covered before
	 Therefore start from i*i */
      SPF[i] = i;
      primes.push_back(i);
      for (T j=i*i; j<=n; j+=i)
	if (isPrime[j]){
	  isPrime[j] = false;
	  SPF[j] = i;
	}
    }
  }

 
  //here, make sure primes are checked for at least square root of n
  map<T,T> optimized_trial_division(T n) {
    map<T, T> pf;
    for (auto p : primes) {
      if (p*p > n) break;
      int count = 0;
      while (n%p==0) ++count, n/=p;
      if (count) pf[p]= count;
    }
    if (n>1) pf[n]= 1;
    return pf;

  }
};

 //this determines if -1 is a square modulu p
  std::optional<int> has_m1_as_sqr(int p)
  {
    for(int i=1; i<p; i++){
      int val = (i*i) % p;
      if(val == p-1) return i;
    }

    return std::nullopt;
  }



//when a number is encoded into a vi, so that, for example, 548 is {8,4,5}
//i.e. vi[0] = 8, vi[1] = 4, vi[2] = 5, then this gets u number back again
long long VI2LL(vi vnum, int begin, int end)
{
  ll ret(0);
  for(int i=end-1; i>=begin; i--) ret = ret*10 + vnum[i];
  return ret;
}

//levenstein distance
// for all i and j, d[i,j] will hold the Levenshtein distance between
// the first i characters of s and the first j characters of t;
// note that d has (m+1)x(n+1) values
int LevenshteinDistance(const char* s, int m, const char* t, int n)
{
  // for all i and j, d[i,j] will hold the Levenshtein distance between
  // the first i characters of s and the first j characters of t
    int d[m+1][n+1];
    memset(d,0,sizeof(d));

    if(m == 0) return n;

    if(n == 0) return m;

    for(int i=0; i<=m; i++) d[i][0] = i;
    for(int j=0;  j<=n; j++) d[0][j] = j;


    for(int j=1; j<=n; j++)
        for(int i=1; i<=m; i++)
        {
            int substitution_cost(0);
            if(s[i-1] != t[j-1]) substitution_cost = 1;

            vi elems;
            elems.push_back(d[i-1][j]+1);
            elems.push_back(d[i][j-1]+1);
            elems.push_back(d[i-1][j-1]+substitution_cost);
            d[i][j] = *min_element(a2z(elems));
        };


    return d[m][n];
}


//getting smallest string, using above algo
string LDstr(const char* cs1, int n, const char* cs2, int m)
{
  vs rows(m+1);
  vvs d(n+1,rows);
  //vvs d[n+1][m+1];
  string s1; s1.assign(cs1,n);
  string s2; s2.assign(cs2,m);

  if(m == 0) return s1;

  if(n == 0) return s2;

  for(int i=1;  i<=n; i++) d[i][0].assign(cs1,i);
  for(int j=1;  j<=m; j++) d[0][j].assign(cs2,j);


  for(int j=1; j<= m; j++)
    for(int i=1; i<=n; i++)
      {
        string & dij = d[i][j];
        string & dijm = d[i][j-1];
        string & dimj = d[i-1][j];
        string & dimjm = d[i-1][j-1];

        if(s1[i-1] == s2[j-1])
          {
            dij = dimjm;
            dij.push_back(s1[i-1]);
          }
        else if(dijm.size() < dimj.size())
          {
            dij = dijm;
            dij.push_back(s2[j-1]);
          }
        else if(dijm.size() > dimj.size())
          {
            dij  = dimj;
            dij.push_back(s1[i-1]);
          }
        else
          {
            dij = dimjm;
            dij.push_back(s1[i-1]);
            dij.push_back(s2[j-1]);
          }
      };
 

  return d[n][m];
}

class node_
{
 public:
  int cost;
  int at;
};

class comp_
{
 public:
  bool operator()(const node_ &leftNode, const node_ &rightNode) const 
  {
    if (leftNode.cost != rightNode.cost) return leftNode.cost < rightNode.cost;
    if (leftNode.at != rightNode.at) return leftNode.at < rightNode.at;
    return false;
  }
};

void dijkstra(node_ start) 
{
  priority_queue<node_,vector<node_>,comp_> s;
  s.push(start);
  while (s.empty() == false) 
    {
      node_ top = s.top();
      s.pop();
      //mark top as visited;
      //check for termination condition (have we reached the target node?)
      //add all of top's unvisited neighbors to the stack.
      
    }
}

//a string tokenizer?
//splits on every character in theDelimiters
/* void */
/* split( vector<string> & theStringVector,  /\* Altered/returned value *\/ */
/*       const  string  & theString, */
/*       const  char c) */
/* { */

/*   size_t  start = 0, end = 0; */

/*   while ( end != string::npos) */
/*     { */
/*       end = theString.find( c, start); */


/*       // If at end, use length=maxLength.  Else use length=end-start. */
/*       theStringVector.push_back( theString.substr( start, */
/*                                                    (end == string::npos) ? string::npos : end - start)); */

/*       // If at end, use start=maxSize.  Else use start=end+delimiter. */
/*       start = (   ( end > (string::npos - 1) ) */
/*                   ?  string::npos  :  end + 1); */
/*     } */
/* } */

//this does NOT clear theStringVector before pushing more tokens
void
split( vector<string> & theStringVector,  /* Altered/returned value */
       const  string  & theString,
       const  string & theDelimiters)
{
  assert(!theDelimiters.empty());
  char buffy[theString.size()];
  strcpy(buffy,theString.c_str());

  char  * str1 = strtok(buffy,theDelimiters.c_str());
  theStringVector.push_back(str1);

  while((str1 = strtok(0,theDelimiters.c_str()))) theStringVector.push_back(str1);
  return;

}

void
split(istringstream & theStream, 
      const  string  & theString,
      const  string & theDelimiters)
{
  assert(!theDelimiters.empty());
  string theStringOut;

  theStringOut.clear();

  char buffy[theString.size()];
  strcpy(buffy,theString.c_str());

  char  * str1 = strtok(buffy,theDelimiters.c_str());
  theStringOut += str1;
  theStringOut.push_back(' ');

  while((str1 = strtok(0,theDelimiters.c_str())))
    {
      theStringOut += str1;
      theStringOut.push_back(' ');
    }

  theStream.str(theStringOut);
  return ;

}

////////////////////////////////////
// end useful stuff
///////////////////////////////////
//some windoze specific stuff.


///////////////////////////////
// geometry
/////////////////////////////
// Given three colinear points p, q, r, the function checks if
// point q lies on line segment 'pr'
bool onSegment(pii p, pii q, pii r)
{
  if (x(q) <= max(x(p), x(r)) && x(q) >= min(x(p), x(r)) &&
      y(q) <= max(y(p), y(r)) && y(q) >= min(y(p), y(r)))
    return true;
 
  return false;
}
 
// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(pii p, pii q, pii r)
{
  // See 10th slides from following link for derivation of the formula
  // http://www.dcs.gla.ac.uk/~pat/52233/slides/Geometry1x1.pdf
  int val = (y(q) - y(p)) * (x(r) - x(q)) -
    (x(q) - x(p)) * (y(r) - y(q));
 
  if (val == 0) return 0;  // colinear
 
  return (val < 0)? 1: 2; // clock or counterclock wise
}

// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(int x1, int y1, int x2, int y2,int x3, int y3)
{

  int val = -x2*y3+x3*y2+x1*y3-x3*y1-x1*y2+x2*y1;
 
  if (val == 0) return 0;  // colinear
 
  return (val > 0)? 1: 2; // clock or counterclock wise
}

// The main function that returns true if line segment 'p1q1'
// and 'p2q2' intersect.
bool do_intersect(pii p1, pii q1, pii p2, pii q2)
{
  // Find the four orientations needed for general and
  // special cases
  int o1 = orientation(p1, q1, p2);
  int o2 = orientation(p1, q1, q2);
  int o3 = orientation(p2, q2, p1);
  int o4 = orientation(p2, q2, q1);
 
  // General case
  if (o1 != o2 && o3 != o4)
    return true;
 
  // Special Cases
  // p1, q1 and p2 are colinear and p2 lies on segment p1q1
  if (o1 == 0 && onSegment(p1, p2, q1)) return true;
 
  // p1, q1 and p2 are colinear and q2 lies on segment p1q1
  if (o2 == 0 && onSegment(p1, q2, q1)) return true;
 
  // p2, q2 and p1 are colinear and p1 lies on segment p2q2
  if (o3 == 0 && onSegment(p2, p1, q2)) return true;
 
  // p2, q2 and q1 are colinear and q1 lies on segment p2q2
  if (o4 == 0 && onSegment(p2, q1, q2)) return true;
 
  return false; // Doesn't fall in any of the above cases
}

//does the above, over a collection
bool do_intersect(pii p, pii q, vpii::iterator path_begin, vpii::iterator path_end)
{
  if(path_begin == path_end) return false;
  path_end--;
  while(path_begin != path_end)
    {
      if(do_intersect(p,q,*path_begin,*(++path_begin))) return true;
    }
  return false;
}

//does the above, over two collections
bool do_intersect(vpii path1, vpii path2)
{
  for(int idx=1; idx<path1.size(); idx++)
    {
      if(!do_intersect(path1[idx-1],path1[idx],path2.begin(),path2.end())) return true;
    }
  return false;
}

