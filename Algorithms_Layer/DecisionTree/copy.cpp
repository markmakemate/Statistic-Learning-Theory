DecisionTree::DecisionTree(map<string,double>* Input) {
	root = NULL;
	sample_num = sizeof(Input);
	__Input=new map<string,double>[sample_num];
	__Input=Input;
}

//selection=0: Regression Tree
//selection==1: Classification Tree
TreeNode<map<string, double> >* DecisionTree::CART(int selection, TreeNode<map<string, double> >* T,double valve) {
	if (selection == 0) {
		if(spliting_criterion.cols()==2){
			return Regression_Tree(this->__Input,T, valve);
		}
		else {
			throw "Please enter the right spliting criterion(for regression tree)!";
		}
	}
	else {
		if(spliting_criterion.cols()==1){
			return Classification_Tree(this->__Input,T, valve);
		}
		else {
			throw "Please enter the right spliting criterion (for classfication tree)!";
		}
	}
}
TreeNode<map<string, double> >* DecisionTree::Regression_Tree(map<string,double>* Input,TreeNode<map<string, double> >* T,double valve) {
	typedef TreeNode<map<string, double> >* node;
	typedef TreeNode<map<string, double> > Node;
	typedef map<string,double>* Table;
	typedef map<string, double> property;
	property::iterator it;
	Table* Subspace;
	Table R1;
	Table R2;
	map<property,double> gini;
	gini=Gini(Input);
	map<property,Table*> LS;
	it=Least_Square().begin();
	Subspace=it->second;
	R1=Subspace[0];
	R2=Subspace[1];
	if(T==NULL){
		T=new Node(it->first,gini.begin()->second);
	}
	if((gini.begin()->second)>valve){
		T->left=Regression_Tree(R1,T->left,valve);
		T->right=Regression_Tree(R2,T->right,valve);
	}
	return T;
}
TreeNode<map<string, double> >* DecisionTree::Classification_Tree(map<string,double>* Input,TreeNode<map<string, double> >* T, double valve) {
	typedef TreeNode<map<string, double> >* node;
	typedef TreeNode<map<string, double> > Node;
	typedef map<string,double> value;
	typedef map<string,double>* Table;
	Table* Subspace;
	Table R1;
	Table R2;
	value gini;
	gini=Gini(__Input);
	value LS;
	LS=this->Classifier(__Input,gini);
	Subspace=LS.begin().second;
	R1=Subspace[0];
	R2=Subspace[1];
	if(T==NULL){
		T=new Node(LS.begin().first,gini.begin().second);
	}
	if(gini.begin().second>valve){
		T->left=Classification_Tree(R1,T->left,valve);
		T->right=Classification_Tree(R2,T->right,valve);
	}
	return T;
}

map<map<string,double>,map<string,double>**> DecisionTree::Least_Square(){
	typedef map<string, double>* Table;
	typedef map<string,double> value;
	map<string,double>::iterator it;
	map<value,Table*> result;
	Table* subspace=NULL;
	Table R1;
	Table R2;
	double min=10;
	double x,sum;
	int dimension=(*(__Input)).size();
	int length=sizeof(__Input)/sizeof(*(__Input));
	for(int i=0;i<dimension;i++){
		for(int j=0;j<sample_num;j++){
			it=(*(__Input+j)).begin();
			x=(*(it+i)).second;
			subspace=this->QuickSort(__Input,dimenson,x);
			R1=subspace[0];
			R2=subspace[1];
			sum=sum(subspace);
			if(sum<min){
				min=sum;
				result.clear();
				result.insert(make_pair((*(it+i)).first,x));
			}
		}
	}
	return result;
}

map<map<string,double>,double> DecisionTree::Gini(map<string,double>* Input){
	typedef map<string,double> value;
	typedef map<value,double> container;
	typedef map<value,int> classified;
	classified space;
	container result;
	int length=sizeof(__Input)/sizeof(*(__Input));
	int dimension=(*(__Input)).size();
	for(int i=0;i<length;i++){
		for(int j=0;j<dimension;j++){

		}
	}
	
}
map<map<string,double>,int> TableProcessor::Partitioner(map<string,double>* __Input,int dimension){
	typedef map<string,double> value;
	value::iterator it;
	value::iterator candidate;
	int position=1;
	value result;
	double x;
	length=sizeof(__Input)/sizeof(*(__Input));
	while(position<length){
		it=(*(__Input+position-1)).begin();
	    x=(*(it+dimension)).second;
		for(int j=position;j<length;j++){
			candidate=(*(__Input+j)).begin();
			if(candidate->second==x){
				swap(__Input,position,j);
				position++;
			}
		}
		result.insert(make_pair(*(__Input+position),position));
		position++;
	}
	return result;
}

void TableProcessor::swap(map<string,double>* __Input,int p1,int p2){
	typedef map<string,double> value;
	value temp;
	temp=*(__Input+p1);
	*(__Input+p1)=*(Input+p2);
	*(__Input+p2)=temp;
	delete temp;
}

map<string, double>** TableProcessor::QuickSort(map<string, double>* __Input,int dimension,double criterion,int begin,int end){
	int q=0;
	end=sizeof(__Input)/sizeof(*(__Input))-1;
	map<string, double>* result[2]=new map<string,double>[end+1];
	if(begin<end){
		int p=this->Partition(__Input,int dimension,double criterion,begin,end);
	    __Input=QuickSort(__Input,criterion,criterion, begin, p-1);
	    __Input=QuickSort(__Input,dimension,criterion, begin, p+1);
	}
	for(int i=0;i<end+1;i++){
		if(*(__Input+i)<=criterion){
			result[i][0]=*(__Input+i);
			q++;
		}
		else{
			result[i-q][1]=*(__Input+i);
		}
	}
	return result;
}

int TableProcessor::Partition(map<string, double>* __Input,int dimension,int begin,int end){
	typedef map<string,double> value;
	int length=sizeof(__Input)/sizeof(*__Input);
	value::iterator it;
	value::iterator candidate;
	it=(*(__Input+end)).begin();
	double x=(*(it+dimension)).second;
	int p=begin-1;
	for(int i=0;i<end;i++){
		candidate=(*(__Input+i)).begin();
		if((*(candidate+dimension)).second<x){
			p++;
			this->swap(__Input,i,p);
		}
	}
	this->swap(__Input,p+1,end);
	return p++;
}


double sum(map<string,double>** Subspace){
	typedef map<String,double>* Table;
	map<string,double>::iterator r1;
	map<string,double>::iterator r2;
	Table R1;
	Table R2;
	double sum1,sum2;
	sum1=0;
	sum2=0;
	double c1,c2;
	c1=0;
	c2=0;
	int size1=sizeof(Subspace[0])
	int size2=sizeof(Subspace[1])
	R1=new map<string,double>[size1];
	R2=new map<string,double>[size2];
	R1=Subspace[0];
	R2=Subspace[1];
	int dimension=(*(R1)).size();
	for(int i=0;i<size1;i++){
		r1=(*(R1+i)).begin();
		c1+=(*(r1+dimension-1)).second;
	}
	c1=c1/size1;
	
	for(int i=0;i<size;i++){
		r2=(*(R2+i)).begin();
		c2+=(*(r1+dimension-1)).second;
	}
	c2=c2/size2;
	for(int i=0;i<size1;i++){
		for(r1=(*(R1)).begin();r1!=(*(R1)).end();++r1){
			sum1+=pow((*r1).second-c1,2);
		}
	}
	for(int i=0;i<size2;i++){
		for(r2=(*(R2)).begin();r2!=(*(R2)).end();++r2){
			sum2+=pow((*r2).second-c2,2);
		}
	}
	return sum1+sum2;
}