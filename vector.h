#include<iostream>
#include<exception>
using namespace std;

/*class out_bound:public exception
{
    public:
        const char* what()
        {
            return "array index out of bound";
        }
};*/


template <class T>
class Vec_tor
{
	T* data;
    int size,capacity;
  public:
  
  	Vec_tor()
    {
      data=new T[15];
      capacity=15;
      size=0;
    }
    
    void push_back(T element)
    {
      if(size==capacity)
      {
          
          T* new_data=new T[2*capacity];
          for(int i=0;i<size;i++)
          new_data[i]=data[i];
          delete(data);
      	  data=new_data;
      }
      data[size]=element;
      size++;
      
    }
    
    int Capacity()
    {	
    	cout<<endl;
    	return capacity;
    }
    
    int Size()
    {
    	
    	return size;
    }
    
    int at(int x)
    {
        cout<<endl;
        if(x>size)
              return -1;
        return data[x];
            
    /*    catch(out_bound &o)
        {
            const char* p=o.what();
            cout<<p<<endl;
            
        }*/
    }
    
    void insert(T element,int pos)
    {
    if(size==capacity)
      {
          
          T* new_data=new T[2*capacity];
          for(int i=0;i<size;i++)
          new_data[i]=data[i];
          delete(data);
          data=new_data;
       }
       
       int j;
       for(j=size;j>=pos;j--)
       {
       	data[j]=data[j-1];
       }
       data[j]=element;
       size++;
       
    }
    
    T& front()
    {
    return *data;
    }
    
    T& back()
    {
    
    return *(data+(size-1));
    }
    
    T pop_back()
    {
    if(size==0)
    {
    cout<<"Underflow";
    return -1;
    }
   	return data[size-1];
    
    }
    
    T operator[](int x)
    {
    if(x<size)
   		return data[x];
    return -1;
    }
    
    void show()
    {
    	for(int i=0;i<size;i++)
        {
        	cout<<data[i]<<" ";
        }
        cout<<endl;
    }
    
friend ostream& operator<<(ostream &out,Vec_tor<int> &v);
    
};




