#include<iostream>
#include "simple_set_and_map.cpp"
std::string mainMenu(){
  std::string menu;
  menu+="-1.\tExit\n";
  menu+="0.\tPrint menu\n";
  menu+="1.\tInsert\n";
  menu+="2.\tSearch by value\n";
  menu+="3.\tSearch by index\n";
  menu+="4.\tSize\n";
  menu+="5.\tDelete one element\n";
  menu+="6.\tDelete everything\n";
  menu+="7.\tPrint all\n";
  return menu;
}
int main(){
  std::string ch;
  std::string inputString;long i;
  ssm::set<std::string> x;
  std::cout<<mainMenu();
  std::cout<<">> ";
  std::cin>>ch;
  while(ch!="-1"){
    if(ch=="0"){std::cout<<mainMenu();}
    if(ch=="1"){
      std::cin>>inputString;
      x.insert(inputString);
    }
    if(ch=="2"){
      std::cin>>inputString;
      i=x.find(inputString);
      if(i==-1){
        std::cout<<"Not found.\n";
        i=x.upperBound(inputString);
        if((i>0)&&(i<x.size())){
          std::cout<<"The lower and upper bound are:\n";
        }
        if(i==0){
          std::cout<<"All terms of the sequence are bigger ";
          std::cout<<"than the requested term \n";
        }
        if(i==x.size()){
          std::cout<<"All terms of the sequence are smaller ";
          std::cout<<"than the requested term\n";
        }
        if(i>0){
          std::cout<<"x["<<i-1<<"] = "<<x[i-1]<<"\n";
        }
        if(i<x.size()){
          std::cout<<"x["<<i<<"] = "<<x[i]<<"\n";
        }
      }
      else{
        std::cout<<i<<"\n";
      }
        std::cout<<"Search that returns index and value:\n";
        std::pair<long,std::string> sIV=x.findIK(inputString);
        std::cout<<sIV.first<<" "<<sIV.second<<"\n";
    }
    if(ch=="3"){ std::cin>>i; std::cout<<x[i]<<"\n"; }
    if(ch=="4"){std::cout<<x.size()<<"\n";}
    if(ch=="5"){std::cin>>inputString;x.erase(inputString);}
    if(ch=="6"){x.clear();}
    if(ch=="7"){
      for(long i=0;i<x.size();++i){
        std::cout<<i<<"\t"<<x[i]<<"\n";
      }
    }
    std::cout<<">> ";
    std::cin>>ch;
  }
  return 0;
}
