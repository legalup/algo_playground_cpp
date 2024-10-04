
#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <limits>
#include <queue>
#include <vector>
#include <tuple>
#include <unordered_map>
#include <map>
#include <set>
#include <list>
#include <string>
#include <algorithm>
#include <bitset>
#include <numeric>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include "algo.h"

using namespace std;

#define MAXTOP 10000000 //this is the biggest topcoder can do


using vert=int;


std::ostream& operator<<(std::ostream& strm,
                         const std::pair<int,int>& kvPair)
{
  strm << "(" << kvPair.first << "," << kvPair.second << ")";
  return strm;
}


int n=25;
vector<vert> verts;
map<int, vector<int>> graph ;
set<vert> used;
set<vert> comp ;
set<vert> H;
set<vert> iHm1;

void dfs(vert v) {
  used.insert(v) ;
  comp.insert(v);
  for(auto to : graph[v]) {
    if notin(to,used) dfs(to);
  }
}

void find_comps() {
  used.clear();
  for(const auto & i : verts){
    if notin(i,used) {
      comp.clear();
      dfs(i);
      cout << "Component:" ;
      for(auto cj : comp) cout << ' ' << cj;
      cout << endl ;
    }
  }
}

int normalize(int vv){
  int mid = (n-1)/2;
  vv = (vv) % n;
  if(vv>mid) vv -= n;
  if(vv<(-mid)) vv+= n;

  return vv;
 
}

vector<int> make_cycle(int imag, int ii)
{
  vector<int> ret;
  ret.push_back(ii);

  fi(0,3){
    ii = normalize(imag*ii);
    ret.push_back(ii);
  }

  return ret;
  
};

void update_graph(int v1, int v2)
{
  v1 = normalize(v1);
  v2 = normalize(v2);
  
  if(graph.count(v1)==0) graph[v1] = vector<vert>();
  if(graph.count(v2)==0) graph[v2] = vector<vert>();

  graph[v1].push_back(v2);
  graph[v2].push_back(v1);
    
}


int main(int argc, char** argv)
{
  //first, lets get a prime, shall we
  int maxp = 100;
  primer<int> pp(maxp);
  int sz = pp.primes.size();
  cout << " size of primes is " << sz << endl;
  int imag = 0;
  for(int nn = sz-1; nn>=0; nn--){
    auto vv = has_m1_as_sqr(pp.primes[nn]);
    if(vv.has_value()){
      n = pp.primes[nn];
      imag = vv.value();
      break;
    }
  }
  
  std::cout << "n is:" << n << " and imag is:" << imag << std::endl;
  int mid = (n-1)/2;
  set<int> vertices;
  fi(1,mid) {
    vertices.insert(i);
    vertices.insert(-i);
    verts.push_back(i);
    verts.push_back(-i);
  };

  verts.push_back(0);

  int counter(0);
  int curr = 1;
  while(!vertices.empty() && curr<=mid){
    if(vertices.count(curr) == 0) {
      curr++;
      continue;
    }
    auto cyc = make_cycle(imag, curr);

    //std::cout << "curr is " << curr << " and cycle is " << cyc[0] << "," << cyc[1] << "," << cyc[2] << "," << cyc[3] << std::endl;

    for(auto vv : cyc) vertices.erase(vv);
    
    if((counter % 2)==0){
      update_graph(cyc[0],cyc[1]);
      update_graph(cyc[1]-1,cyc[2]-1);
      update_graph(cyc[2],cyc[3]);
      update_graph(cyc[3]-1,cyc[0]-1);

      H.insert(normalize(cyc[0]));
      H.insert(normalize(cyc[1]));
      H.insert(normalize(cyc[2]));
      H.insert(normalize(cyc[3]));

      iHm1.insert(normalize(cyc[1]-1));
      iHm1.insert(normalize(cyc[2]-1));
      iHm1.insert(normalize(cyc[3]-1));
      iHm1.insert(normalize(cyc[0]-1));
	       
    }
    else{
      update_graph(cyc[0]-1,cyc[1]-1);
      update_graph(cyc[1],cyc[2]);
      update_graph(cyc[2]-1,cyc[3]-1);
      update_graph(cyc[3],cyc[0]);

      H.insert(normalize(cyc[0]));
      H.insert(normalize(cyc[1]));
      H.insert(normalize(cyc[2]));
      H.insert(normalize(cyc[3]));

      iHm1.insert(normalize(cyc[1]-1));
      iHm1.insert(normalize(cyc[2]-1));
      iHm1.insert(normalize(cyc[3]-1));
      iHm1.insert(normalize(cyc[0]-1));
    }

    counter++;
    curr++;
  }

  cout << "size of graph is " << graph.size() << std::endl;

  cout << graph << endl;;

  cout << "H:" <<  H << endl;
  cout << "iH - 1:" << iHm1 << endl;
  
  find_comps();
  
}
