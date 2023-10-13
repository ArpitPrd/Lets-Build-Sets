#include <iostream>
#include <vector>

using namespace std;

class SET {
	public:
	vector <int> arr;
	bool BelongsTo(int item) {
		int i = 0;
		int j = arr.size();
		int mid;
		while (i < j && j-i!=1){
			mid = (i+j)/2;
			if (arr[mid] > item){
				j = mid;
			}
			else if(arr[mid] < item){
				i = mid;
			}
			else {
				return true;
			}
		}
		if (j-i == 1){
			if (arr.size () == 1){
				if (item == arr[0]){
					return true;
				}
				else {
					return false;
				}
			}
			else {
				if ( arr[i] == item || arr[ j] == item ){
					return true;
				}
				else {
					return false;
				}
			}
		}
		else if (arr.size() == 0){
			return false;
		}	
		return false;
	}
	int temp_size () {
		return arr.size();
	}

	int FindLoc( int item ) {
		int i = 0;
		int j = arr.size();
		int mid = 0;
		while (i < j && j-i!=1){
			mid = (i + j)/2;
			if (arr[mid] > item){
				j = mid;
			}
			else{
				i = mid;
			}
		}
		if (j- i == 1){
			if (arr.size() == 1){
				if (item > arr[0]){
					return 1;
				}
				else {
					return 0;
				}
			}
			else if (j == arr.size()){
				return j;
			}
			else{
				if (item < arr[i]){
					return i;
				}
				else if ( arr[i] < item && item < arr[j] ){
					return j;
				}
				else{
					return j;
				}
			}
		}
		return 0;	
	}
	void Size () {
		cout << arr.size() << endl;
	}

	void insrt(int item) {
		if (this->BelongsTo(item)){
			;	
		}
		else {
			int loc = FindLoc(item);
			arr.insert( arr.begin() + loc, item );
		}
		cout << arr.size() << endl;
	}
	void print (){
		if (arr.size() > 0){
			for (int i = 0; i < arr.size()-1; i++) {
				cout << arr[i] << ",";
			}
			cout << arr[arr.size()-1] << endl;
		}
		else {
			cout << endl;
		}
	}
	int temp_FindLoc(int item){
		int i = 0;
                int j = arr.size();
                int mid = 0;
                while (i < j && j-i!=1){
                        mid = (i + j)/2;
                        if (arr[mid] > item){
                                j = mid;
                        }
                        else if (arr[mid] < item){
                                i = mid;
                        }
			else {
				return mid;	
			}
		}
		if (j-i == 1){
			if (arr.size() == 1){
				return 0;
			}
			else if (i == 0){
				if (arr[i] == item){
					return 0;
				}
			}
		}
		return 0;
	}
	void Delete ( int item ){
			if (this->BelongsTo(item)){
				int loc = this->temp_FindLoc(item);
				arr.erase(arr.begin() + loc);
				cout << arr.size() << endl;
			}
			else{
				cout << 0 << endl;
			}
	}
	int getItem (int index){
		return arr[index];
	}
	void Union ( SET s){
		for (int i = 0; i < s.temp_size(); i++){
			if (not this->BelongsTo(s.getItem(i))){
				int loc = this->FindLoc( s.getItem ( i));
				arr.insert(arr.begin() + i, s.getItem(i));
			}
		}
		cout << arr.size() << endl;
	}
	void Intersection ( SET s){
		vector <int> ind_val;
		for (int i = 0; i < arr.size(); i++){
			if (not s.BelongsTo(arr[i])){
				ind_val.push_back(arr[i]);
			}
		}
		for (int j = 0; j < ind_val.size(); j++){
			int loc = this->temp_FindLoc( ind_val[j] );
			arr.erase( arr.begin() + loc );
		}
		cout << arr.size() << endl;
	}
	void Difference ( SET s ){
		vector <int> ind_val;
		for (int i = 0; i < s.temp_size(); i++){
			if (this->BelongsTo( s.getItem (i) ) ){
				ind_val.push_back( s.getItem(i) ); 	
			}
		}
		for (int j = 0; j < ind_val.size(); j++){
			int loc = this->temp_FindLoc( ind_val[j] );
			arr.erase( arr.begin() + loc );
		}
		cout << arr.size() << endl;
	}
	void SymDifference ( SET s ){
		vector <int> add;
		vector <int> del;
		for (int i = 0; i < s.temp_size(); i++){
			if ( this->BelongsTo(s.getItem(i)) ){
				del.push_back(s.getItem(i));
			}
			else{
				add.push_back(s.getItem(i));
			}
		}
		for (int j = 0; j < del.size(); j++){
			int loc = this->temp_FindLoc( del[j] );
			arr.erase( arr.begin() + loc );
		}
		for (int k = 0; k < add.size(); k++){
			int loc = this->FindLoc( add[k]);
                        arr.insert(arr.begin() + loc, add[k]);
		} 
	cout << arr.size() << endl;
	}
};

int main () {
	vector <SET> set_loc;
	int command;
	while ( scanf("%d", &command) != EOF){
		//cout << command << " command" << endl;
		int set;
		//cout << 3 << endl;
		cin >> set;
		//cout << set << " set" << endl;
		if (command == 6 || command == 9){
/*6*/			if (command == 6){
				if (set_loc.size()-1 >= set){
					set_loc[set].Size();
				}
				else {
					SET s;
					set_loc.push_back(s);
					set_loc[set].Size();
				}
			}
/*9*/			else{
				if (set_loc.size()-1 >= set){
					set_loc[set].print();
				}
				else{
					SET s;
					set_loc.push_back(s);
					set_loc[set].print();
				}
			}
		}	
		else {
			int val;
			cin >> val;
			//cout << val << " val" << endl;
			//cout << set_loc.size()<< " " << "size" << endl;
/*1*/			if (command == 1) {
				int b = set_loc.size()-1;
				//cout << b << endl;
				//cout << v << endl;
				if (set <= b){
					set_loc[set].insrt(val);
				}
				else {
					SET set_ins;
					set_loc.push_back(set_ins);
					set_loc[set].insrt(val);
				}
			}
/*2*/			else if (command == 2){
				int b = set_loc.size()-1;
				if (set <= b){
					set_loc[set].Delete( val);
				}
				else{
					cout << -1 << endl;
				}	
			}
			else if ( command == 3 ){
/*3*/				int b = set_loc.size()- 1;
				if ( set <= b ){
					if ( set_loc[set].BelongsTo(val) ){
						cout << 1 << endl;
					}
					else {
						cout << 0 << endl;
					}
				}
				else {
					cout << -1 << endl;
				}
			}
/*4*/			else if ( command == 4){
				int b = set_loc.size()- 1;
				if ( set <= b and val <= b ){
					set_loc[set].Union(set_loc[val]);
				}
				else if ( set <= b and val > b){
					SET s;
					set_loc.push_back(s);
					set_loc[set].Union(set_loc[val]);
				}
				else if ( set > b and val <= b){
					SET s;
					set_loc.push_back(s);
					set_loc[set].Union(set_loc[val]);
				}
				else {
					SET s1;
					SET s2;
					set_loc.push_back(s1);
					set_loc.push_back(s2);
					set_loc[set].Union(set_loc[val]);
				}
			}
/*5*/			else if ( command  == 5 ){
				int b = set_loc.size()- 1;
				if ( set <= b && val <= b ){
					set_loc[set].Intersection(set_loc[val]);
				}
				else if ( set <= b && val > b){
					SET s;
					set_loc.push_back(s);
					set_loc[set].Intersection(set_loc[val]);
				}
				else if ( set > b && val <= b){
					SET s;
					set_loc.push_back(s);
					set_loc[set].Intersection(set_loc[val]);
				}
				else {
					SET s1;
					SET s2;
					set_loc.push_back(s1);
					set_loc.push_back(s2);
					set_loc[set].Intersection(set_loc[val]);
				}
			}
/*7*/			else if ( command == 7 ){
				int b = set_loc.size()- 1;
				if ( set <= b && val <= b ){
					set_loc[set].Difference(set_loc[val]);
				}
				else if ( set <= b && val > b){
					SET s;
					set_loc.push_back(s);
					set_loc[set].Difference(set_loc[val]);
				}
				else if ( set > b && val <= b ) {
					SET s;
					set_loc.push_back(s);
					set_loc[set].Difference(set_loc[val]);
				}
				else {
					SET s1;
					SET s2;
					set_loc.push_back(s1);
					set_loc.push_back(s2);
					set_loc[set].Difference(set_loc[val]);
				}
			}
/*8*/			else if ( command == 8 ){
				int b = set_loc.size()- 1;
                                if ( set <= b && val <= b ){
                                        set_loc[set].SymDifference(set_loc[val]);
                                }
                                else if ( set <= b && val > b){
                                        SET s;
                                        set_loc.push_back(s);
                                        set_loc[set].SymDifference(set_loc[val]);
                                }
                                else if ( set > b && val <= b ) {
                                        SET s;
                                        set_loc.push_back(s);
                                        set_loc[set].SymDifference(set_loc[val]);
                                }
                                else {
                                        SET s1;
                                        SET s2;
                                        set_loc.push_back(s1);
                                        set_loc.push_back(s2);
                                        set_loc[set].SymDifference(set_loc[val]);
                                }

			}
		}
	}
	
	return 0;
}
