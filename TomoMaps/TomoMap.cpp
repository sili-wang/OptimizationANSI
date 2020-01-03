#include <iostream>
#include <stdio.h>
#include <unordered_set>
#include <list>
#include <algorithm>
#include <math.h>
#include <string.h>

using namespace std;

int dx,dy,dz;
unordered_set<double> uniquevalues;
double range;
double numbercolors;
list<double> key_list;
int **colormatrix;

void print_matrix(double **mat);
void print_uniquevalues(unordered_set<double> uniquevalues);
void sort_uniquevalues(unordered_set<double> uniquevalues);
void print_list();
void fill_colormatrix(double **mat);

int main(int argc,char *argv[])
{
	char filename[200];                            //name file to receive as parameter

        if(argc != 3)
        {
	      printf("usage: tmo_file number_colors \n");
	      return 0;
	}
	strcpy(filename,argv[1]);
	numbercolors = atoi(argv[2]);
	cout<<"Input File: "<<filename<<endl;

    //numbercolors = 250;

    FILE *tmo;
    double value=0.0;

    double **mat;
    tmo = fopen(filename,"r");
    if(tmo==NULL){
        cout<<"Error Reading File TMO"<<endl;
        return 0;
    }
    else{
        for(int i=0;i<12;i++)
            fscanf(tmo,"%lf",&value);
        fscanf(tmo,"%d",&dx);
        fscanf(tmo,"%d",&dy);
        fscanf(tmo,"%d",&dz);

        mat = new double*[dx];
        for(int i=0;i<dx;i++)
            mat[i] = new double[dy];

        for(int i=0;i<dx;i++){
            for(int j=0;j<dy;j++){
                fscanf(tmo,"%lf",&value);
                mat[i][j] = value;
                uniquevalues.insert(value);
            }
        }

        fclose(tmo);
    }
    print_uniquevalues(uniquevalues);
    sort_uniquevalues(uniquevalues);
    //print_list();
    fill_colormatrix(mat);
    return 0;
}

void print_uniquevalues(unordered_set<double> uniquevalues){

   cout<<"Number of unique elements: "<<uniquevalues.size()<<endl;
   range = (double)uniquevalues.size()/(double)numbercolors;
   //range = ceil((double)uniquevalues.size()/(double)numbercolors);
   cout<<"Number of colors per unique elements: "<<range<<endl;

 //  for ( auto it = uniquevalues.begin(); it != uniquevalues.end(); ++it )
      // cout << " " << *it << endl;

}
void sort_uniquevalues(unordered_set<double> uniquevalues){


    for ( auto it = uniquevalues.begin(); it != uniquevalues.end(); ++it )
            key_list.push_back(*it);
    key_list.sort();

}

void print_list(){

    list<double>::iterator i;
	for( i = key_list.begin(); i != key_list.end(); ++i){
		cout << *i << endl;
    }
	cout << endl;

}
void print_matrix(double **mat){

    int initial=50;
        for(int i=initial;i<dx;i++){
            for(int j=0;j<dy;j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
            break;
        }

}


void fill_colormatrix(double **mat){
    FILE *f1;

    int cont=0;
    int position;
    double value;
    int newvalue;
    colormatrix = new int*[dx];
        for(int i=0;i<dx;i++)
            colormatrix[i] = new int[dy];


    f1 = fopen("printing.dat","w");

    if(f1!=NULL){

    fprintf(f1,"%d %d ",dy,dx);

    for(int i=dy-1;i>=0;i--){
       for(int j=0;j<dx;j++){
            value = mat[j][i];

            list<double>::iterator pos;
            pos = find(key_list.begin(), key_list.end(), value);
            position = distance(key_list.begin(), pos);
            newvalue = (int)position/range;
            colormatrix[j][i] = newvalue;
            fprintf(f1,"%d ",colormatrix[j][i]);


       }


    }
    fclose(f1);
    cout<<"No repeted numbers: "<<key_list.size()<<endl;
    }


}
