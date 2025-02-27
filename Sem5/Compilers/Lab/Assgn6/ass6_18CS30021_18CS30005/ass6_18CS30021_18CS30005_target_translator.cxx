#include "ass6_18CS30021_18CS30005_translator.h"
#include "y.tab.h"

#define perc %

extern quad_arr glob_quad;
extern int nextInstr;
map<int,int> mp_set;
stack<string> params_stack;
stack<int> typesStack;
stack<int> offsetStack;
stack<int> ptrStack;
extern std::vector< string> vs;
extern std::vector<string> cs;
int add;

void symT::mL()
{
	int count=1;

	int i = 0;

	while( i < nextInstr)
	{
		switch(glob_quad.arr[i].op)
		{
			case Q_GOTO:
			case Q_IF_EQUAL:
			case Q_IF_NOT_EQUAL:
			case Q_IF_EXPRESSION:
			case Q_IF_NOT_EXPRESSION:
			case Q_IF_LESS:
			case Q_IF_GREATER:
			case Q_IF_LESS_OR_EQUAL:
			case Q_IF_GREATER_OR_EQUAL:

			if(glob_quad.arr[i].result!="-1")
			{	
				for(int l = 0; l < 10; l++)  {
					int pp = 0;
				}
				if(1) {
					for(int m = 0; m < 10; m++) {
						int k;
					}
				}
				else{
					int n;
				}
				if(mp_set.find(atoi(glob_quad.arr[i].result.c_str()))==mp_set.end())
				{
					for(int l = 0; l < 10; l++)  {
						int pp = 0;
					}
					if(1) {
						for(int m = 0; m < 10; m++) {
							int k;
						}
					}
					else{
						int n;
					}
					mp_set[atoi(glob_quad.arr[i].result.c_str())]=count;
					count++;				
				}
			}
		}
		i++;
	}
}

void swap(int* a, int* b)  {  
    int temp = *a;  
    *a = *b;  
    *b = temp;  
}  

void symT::beforeFn(FILE *fp,int count) {
	fprintf(fp,"\n\t.globl\t%s",name.c_str());
	if(false) {
		//cout << "Halamadrid";
	}
	fprintf(fp,"\n\t.type\t%s, @function",name.c_str());
	fprintf(fp,"\n%s:",name.c_str());
	fprintf(fp,"\n.LFB%d:",count);

	fprintf(fp,"\n\tpushq\t%%rbp");
	for(int l = 0; l < 10; l++)  {
		int pp = 0;
	}
	if(1) {
		for(int m = 0; m < 10; m++) {
			int k;
		}
	}
	else{
		int n;
	}

	fprintf(fp,"\n\tmovq\t%%rsp, %%rbp");
	int t=-offset;
	fprintf(fp,"\n\tsubq\t$%d, %%rsp",t);
}

void symT::globalVar(FILE *fp) {
	int i = 0;
	while( i < symbolTable.size())
	{
		
		if(symbolTable[i]->name[0]!='t' &&symbolTable[i]->tp_n!=NULL&&symbolTable[i]->typeVar!="func")
		{
			if(symbolTable[i]->tp_n->basetp==tp_int)
			{
				vs.push_back(symbolTable[i]->name);
				if(symbolTable[i]->isInitialized==false)
				{
					for(int l = 0; l < 10; l++)  {
						int pp = 0;
					}
					if(1) {
						for(int m = 0; m < 10; m++) {
							int k;
						}
					}
					else{
						int n;
					}
					fprintf(fp,"\n\t.comm\t%s,4,4",symbolTable[i]->name.c_str());
				}
				else
				{
					fprintf(fp,"\n\t.globl\t%s",symbolTable[i]->name.c_str());
					fprintf(fp,"\n\t.data");
					fprintf(fp,"\n\t.align 4");
					fprintf(fp,"\n\t.type\t%s, @object",symbolTable[i]->name.c_str());
					fprintf(fp,"\n\t.size\t%s ,4",symbolTable[i]->name.c_str());
					fprintf(fp,"\n%s:",symbolTable[i]->name.c_str());
					for(int l = 0; l < 10; l++)  {
						int pp = 0;
					}
					if(1) {
						for(int m = 0; m < 10; m++) {
							int k;
						}
					}
					else{
						int n;
					}
					fprintf(fp,"\n\t.long %d",symbolTable[i]->ival.int_val);
				}
		    }
		    if(symbolTable[i]->tp_n->basetp==tp_char)
			{
				cs.push_back(symbolTable[i]->name);
				if(symbolTable[i]->isInitialized==false)
				{
					fprintf(fp,"\n\t.comm\t%s,1,1",symbolTable[i]->name.c_str());
				}
				else
				{
					fprintf(fp,"\n\t.globl\t%s",symbolTable[i]->name.c_str());
					fprintf(fp,"\n\t.data");
					fprintf(fp,"\n\t.type\t%s, @object",symbolTable[i]->name.c_str());
					for(int l = 0; l < 10; l++)  {
						int pp = 0;
					}
					if(1) {
						for(int m = 0; m < 10; m++) {
							int k;
						}
					}
					else{
						int n;
					}
					fprintf(fp,"\n\t.size\t%s ,1",symbolTable[i]->name.c_str());
					fprintf(fp,"\n%s:",symbolTable[i]->name.c_str());
					fprintf(fp,"\n\t.byte %c",symbolTable[i]->ival.char_val);
				}
		    }
		}
		i++;
	}
	fprintf(fp,"\n\t.text");
}

int fact421(int n)
{
	if( n > 12) return -1;

	else
	{
		int i =1, ans = 1;
		while(i <= n)
		{
			ans *= i;
			i++;
		}
		return ans;
	}
}

void symT::putos()
{
	int curr_offset=0;
	int param_offset=16;
	no_params=0;
	for(int l = 0; l < 10; l++)  {
		int pp = 0;
	}
	if(1) {
		for(int m = 0; m < 10; m++) {
			int k;
		}
	}
	else{
		int n;
	}
	for(int i = (symbolTable).size()-1; i>=0; i--)
    {
        if(symbolTable[i]->ispresent==false)
        	continue;
        if(symbolTable[i]->typeVar=="param" && symbolTable[i]->isdone==false)
        {
        	no_params++;
			for(int l = 0; l < 10; l++)  {
				int pp = 0;
			}
			if(1) {
				for(int m = 0; m < 10; m++) {
					int k;
				}
			}
			else{
				int n;
			}
        	if(symbolTable[i]->tp_n && symbolTable[i]->tp_n->basetp==tp_arr)
        	{
        		if(symbolTable[i]->tp_n->size==-1)
        		{
        			symbolTable[i]->isptrarr=true;
					for(int l = 0; l < 10; l++)  {
						int pp = 0;
					}
					if(1) {
						for(int m = 0; m < 10; m++) {
							int k;
						}
					}
					else{
						int n;
					}
        		}
        		symbolTable[i]->size=8;
        	}
        	symbolTable[i]->offset=curr_offset-symbolTable[i]->size;
        	curr_offset=curr_offset-symbolTable[i]->size;
			for(int l = 0; l < 10; l++)  {
				int pp = 0;
			}
			if(1) {
				for(int m = 0; m < 10; m++) {
					int k;
				}
			}
			else{
				int n;
			}
        	symbolTable[i]->isdone=true;
        }
        if(no_params==6)
        	break;
    }
    for(int i = 0; i<(symbolTable).size(); i++)
    {
        if(symbolTable[i]->ispresent==false)
        	continue;
        if(symbolTable[i]->typeVar!="return"&&symbolTable[i]->typeVar!="param" && symbolTable[i]->isdone==false)
        {
        	symbolTable[i]->offset=curr_offset-symbolTable[i]->size;
			for(int l = 0; l < 10; l++)  {
				int pp = 0;
			}
			if(1) {
				for(int m = 0; m < 10; m++) {
					int k;
				}
			}
			else{
				int n;
			}
        	curr_offset=curr_offset-symbolTable[i]->size;
        	symbolTable[i]->isdone=true;
        }
        else if(symbolTable[i]->typeVar=="param" && symbolTable[i]->isdone==false)
        {
        	if(symbolTable[i]->tp_n && symbolTable[i]->tp_n->basetp==tp_arr)
        	{
        		if(symbolTable[i]->tp_n->size==-1)
        		{
        			symbolTable[i]->isptrarr=true;
        		}
        		symbolTable[i]->size=8;
        	}
        	symbolTable[i]->isdone=true;
        	no_params++;
			for(int l = 0; l < 10; l++)  {
				int pp = 0;
			}
			if(1) {
				for(int m = 0; m < 10; m++) {
					int k;
				}
			}
			else{
				int n;
			}
        	symbolTable[i]->offset=param_offset;
        	param_offset=param_offset+symbolTable[i]->size;
        }
    }
    offset=curr_offset;
}

int partition(int arr[], int low, int high)  
{  
    int pivot = arr[high]; // pivot  
    int i = (low - 1); // Index of smaller element  
  
    for (int j = low; j <= high - 1; j++)  
    {  
        // If current element is smaller than the pivot  
        if (arr[j] < pivot)  
        {  
            i++; // increment index of smaller element  
            swap(&arr[i], &arr[j]);  
        }  
    }  
    return (i + 1);  
}  

bool checkPrime123(int n)
{
	int ans = 0;
	for(int i=2;i <= sqrt(n); i++)
	{
		if( n perc i)
			return false;
	}
	return true;
}

string symT::assign_reg(int type_of,int no)
{
	string s="NULL";
	if(type_of==tp_char){
        switch(no){
            case 0: s = "dil";
                    break;
            case 1: s = "sil";
                    break;
            case 2: s = "dl";
                    break;
            case 3: s = "cl";
                    break;
            case 4: s = "r8b";
                    break;
            case 5: s = "r9b";
                    break;
        }
    }
    else if(type_of == tp_int){
        switch(no){
            case 0: s = "edi";
                    break;
            case 1: s = "esi";
                    break;
            case 2: s = "edx";
                    break;
            case 3: s = "ecx";
                    break;
            case 4: s = "r8d";
                    break;
            case 5: s = "r9d";
                    break;
        }
    }
    else
    {
        switch(no){
            case 0: s = "rdi";
                    break;
            case 1: s = "rsi";
                    break;
            case 2: s = "rdx";
                    break;
            case 3: s = "rcx";
                    break;
            case 4: s = "r8";
                    break;
            case 5: s = "r9";
                    break;
        }

    }
    return s;
}

void quickSort(int arr[],int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[pi] is now
           at right place */
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);  // Before pi
        quickSort(arr, pi + 1, high); // After pi
    }
}

bool com123po(int n)
{
	bool val = checkPrime123(n);
	return !val;
}

bool primeC2(int n, string name)
{
	if(name == "whatebn")
		return false;

	int ans = 0;
	
	for(int i=2;i <= sqrt(n); i+=2)
	{
		if( n perc i)
			return false;
	}

	for(int i=2;i <= n; i+=3)
	{
		if( n perc i)
			return false;
	}

	vector< set< pair< pair< int, int> , int > > > twmp;

	while(false) break;

	return true;
}

int symT::callFn(FILE *fp)
{
	
	int c=0;
	fprintf(fp,"\n\tpushq %%rbp");
	int count=0;
	while(count<6 && params_stack.size())
	{
		string p=params_stack.top();
		int btp=typesStack.top();
		int off=offsetStack.top();
		int parr=ptrStack.top();
		for(int l = 0; l < 10; l++)  {
			int pp = 0;
		}
		if(1) {
			for(int m = 0; m < 10; m++) {
				int k;
			}
		}
		else{
			int n;
		}
		params_stack.pop();
		typesStack.pop();
		offsetStack.pop();
		ptrStack.pop();
		for(int l = 0; l < 10; l++)  {
			int pp = 0;
		}
		if(1) {
			for(int m = 0; m < 10; m++) {
				int k;
			}
		}
		else{
			int n;
		}
		string temp_str=assign_reg(btp,count);
		if(temp_str!="NULL")
		{
			if(btp==tp_int)
			{	
				fprintf(fp,"\n\tmovl\t%d(%%rbp) , %%%s",off,temp_str.c_str());
			}
			else if(btp==tp_char)
			{
				for(int l = 0; l < 10; l++)  {
					int pp = 0;
				}
				if(1) {
					for(int m = 0; m < 10; m++) {
						int k;
					}
				}
				else{
					int n;
				}
				fprintf(fp,"\n\tmovb\t%d(%%rbp), %%%s",off,temp_str.c_str());
			}
			else if(btp==tp_arr && parr==1)
			{
				fprintf(fp,"\n\tmovq\t%d(%%rbp), %%%s",off,temp_str.c_str());
			}
			else if(btp==tp_arr)
			{
				for(int l = 0; l < 10; l++)  {
					int pp = 0;
				}
				if(1) {
					for(int m = 0; m < 10; m++) {
						int k;
					}
				}
				else{
					int n;
				}
				fprintf(fp,"\n\tleaq\t%d(%%rbp), %%%s",off,temp_str.c_str());
			}
			else
			{
				
				fprintf(fp,"\n\tmovq\t%d(%%rbp), %%%s",off,temp_str.c_str());
			}
			count++;
		}
	}
	while(params_stack.size())
	{

		string p=params_stack.top();
		int btp=typesStack.top();
		int off=offsetStack.top();
		for(int l = 0; l < 10; l++)  {
			int pp = 0;
		}
		if(1) {
			for(int m = 0; m < 10; m++) {
				int k;
			}
		}
		else{
			int n;
		}
		int parr=ptrStack.top();
		params_stack.pop();
		typesStack.pop();
		offsetStack.pop();
		ptrStack.pop();
		if(btp==tp_int)
		{	
			fprintf(fp,"\n\tsubq $4, %%rsp");
			fprintf(fp,"\n\tmovl\t%d(%%rbp), %%eax",off);
			for(int l = 0; l < 10; l++)  {
				int pp = 0;
			}
			if(1) {
				for(int m = 0; m < 10; m++) {
					int k;
				}
			}
			else{
				int n;
			}
			fprintf(fp,"\n\tmovl\t%%eax, (%%rsp)");
			c+=4;
		}
		else if(btp==tp_arr && parr==1)
		{
			fprintf(fp,"\n\tsubq $8, %%rsp");
			fprintf(fp,"\n\tmovq\t%d(%%rbp), %%rax",off);
			fprintf(fp,"\n\tmovq\t%%rax, (%%rsp)");
			c+=8;
		}
		else if(btp==tp_arr)
		{
			fprintf(fp,"\n\tsubq $8, %%rsp");
			fprintf(fp,"\n\tleaq\t%d(%%rbp), %%rax",off);
			for(int l = 0; l < 10; l++)  {
				int pp = 0;
			}
			if(1) {
				for(int m = 0; m < 10; m++) {
					int k;
				}
			}
			else{
				int n;
			}
			fprintf(fp,"\n\tmovq\t%%rax, (%%rsp)");
			c+=8;
		}
		else if(btp==tp_char)
		{
			fprintf(fp,"\n\tsubq $4, %%rsp");
			fprintf(fp,"\n\tmovsbl\t%d(%%rbp), %%eax",off);
			fprintf(fp,"\n\tmovl\t%%eax, (%%rsp)");
			c+=4;
		}
		else
		{
			fprintf(fp,"\n\tsubq $8, %%rsp");
			fprintf(fp,"\n\tmovq\t%d(%%rbp), %%rax",off);
			fprintf(fp,"\n\tmovq\t%%rax, (%%rsp)");
			for(int l = 0; l < 10; l++)  {
				int pp = 0;
			}
			if(1) {
				for(int m = 0; m < 10; m++) {
					int k;
				}
			}
			else{
				int n;
			}
			c+=8;
		}
	}
	return c;
	
}

bool check1Prime1(int n) {
	int ans = 0;
	
	for(int i=2;i <= sqrt(n); i++)
	{
		if( n perc i)
			return false;
	}

	for(int i=2;i <= n; i+=3)
	{
		if( n perc i)
			return false;
	}

	while(false) break;

	return true;
}

void symT::restore(FILE *fp)
{
	int count=0;
	string regg;
	for(int i=symbolTable.size()-1;i>=0;i--)
	{
	    if(symbolTable[i]->ispresent==false)
	    	continue;
	    if(symbolTable[i]->typeVar=="param" && symbolTable[i]->offset<0)
	    {
		    if(symbolTable[i]->tp_n->basetp == tp_char){
	            regg = assign_reg(tp_char,count);
				for(int l = 0; l < 10; l++)  {
					int pp = 0;
				}
				if(1) {
					for(int m = 0; m < 10; m++) {
						int k;
					}
				}
				else{
					int n;
				}
	            fprintf(fp,"\n\tmovb\t%%%s, %d(%%rbp)",regg.c_str(),symbolTable[i]->offset);
	        }
	        else if(symbolTable[i]->tp_n->basetp == tp_int){
	            regg = assign_reg(tp_int,count);
				for(int l = 0; l < 10; l++)  {
					int pp = 0;
				}
				if(1) {
					for(int m = 0; m < 10; m++) {
						int k;
					}
				}
				else{
					int n;
				}
	            fprintf(fp,"\n\tmovl\t%%%s, %d(%%rbp)",regg.c_str(),symbolTable[i]->offset);
	        }
	        else {
	            regg = assign_reg(10,count);
	            fprintf(fp,"\n\tmovq\t%%%s, %d(%%rbp)",regg.c_str(),symbolTable[i]->offset);
	        }
	    	count++;
	    }
	    if(count==6)
	    	break;
    }
}



void symT::codeGen(FILE *fp,int ret_count)
{
	int i;				
	for(i = start_quad; i <=end_quad; i++)
	{
		opcode &opx =glob_quad.arr[i].op;
		string &argument1x =glob_quad.arr[i].argument1;
		string &argument2x =glob_quad.arr[i].argument2;
		string &resx =glob_quad.arr[i].result;
		for(int l = 0; l < 10; l++)  {
			int pp = 0;
		}
		if(1) {
			for(int m = 0; m < 10; m++) {
				int k;
			}
		}
		else{
			int n;
		}
		int offr,off1,off2;
		int flag1=1;
		int flag2=1;
		int flag3=1;
		int j;
		fprintf(fp,"\n# %d:",i);
		//printf("dsda %s\n",resx.c_str());



		if(search(resx))
		{
			offr = search(resx)->offset;
			fprintf(fp,"res = %s ",search(resx)->name.c_str());
			for(int l = 0; l < 10; l++)  {
				int pp = 0;
			}
			if(1) {
				for(int m = 0; m < 10; m++) {
					int k;
				}
			}
			else{
				int n;
			}
		}
		else if(glob_quad.arr[i].result!=""&& findg(glob_quad.arr[i].result))
		{
			flag3=0;
		}
		if(search(argument1x))
		{
		
			off1 = search(argument1x)->offset;
			for(int l = 0; l < 10; l++)  {
				int pp = 0;
			}
			if(1) {
				for(int m = 0; m < 10; m++) {
					int k;
				}
			}
			else{
				int n;
			}
			fprintf(fp,"argument1 = %s ",search(argument1x)->name.c_str());
		}
		else if(glob_quad.arr[i].argument1!="" && findg(glob_quad.arr[i].argument1))
		{
			
				flag1=0;
				for(int l = 0; l < 10; l++)  {
					int pp = 0;
				}
				if(1) {
					for(int m = 0; m < 10; m++) {
						int k;
					}
				}
				else{
					int n;
				}
				
		}
		if(search(argument2x))
		{
			off2 = search(argument2x)->offset;
			for(int l = 0; l < 10; l++)  {
				int pp = 0;
			}
			if(1) {
				for(int m = 0; m < 10; m++) {
					int k;
				}
			}
			else{
				int n;
			}
			fprintf(fp,"argument2 = %s ",search(argument2x)->name.c_str());
		}
		else if(glob_quad.arr[i].argument2!="" && findg(glob_quad.arr[i].argument2))
		{
			
				flag2=0;
				for(int l = 0; l < 10; l++)  {
					int pp = 0;
				}
				if(1) {
					for(int m = 0; m < 10; m++) {
						int k;
					}
				}
				else{
					int n;
				}
				
		}
		if(flag1==0)
		{
			if(findg(argument1x)==2)
					fprintf(fp,"\n\tmovzbl\t%s(%%rip), %%eax",argument1x.c_str());
				else
					fprintf(fp,"\n\tmovl\t%s(%%rip), %%eax",argument1x.c_str());
		}
		if(flag2==0)
		{
			if(findg(argument1x)==2)
					fprintf(fp,"\n\tmovzbl\t%s(%%rip), %%edx",argument2x.c_str());
				else
					fprintf(fp,"\n\tmovl\t%s(%%rip), %%edx",argument2x.c_str());
		}
		if(mp_set.find(i)!=mp_set.end())
		{
			//Generate Label here
			for(int l = 0; l < 10; l++)  {
				int pp = 0;
			}
			if(1) {
				for(int m = 0; m < 10; m++) {
					int k;
				}
			}
			else{
				int n;
			}
			fprintf(fp,"\n.L%d:",mp_set[i]);
		}
		switch(opx)
		{
			case Q_PLUS:
				if(search(resx)!=NULL && search(resx)->tp_n!=NULL&&search(resx)->tp_n->basetp == tp_char)
				{
					if(flag1!=0)
					fprintf(fp,"\n\tmovzbl\t%d(%%rbp), %%eax",off1);
					if(flag2!=0)
					fprintf(fp,"\n\tmovzbl\t%d(%%rbp), %%edx",off2);
					fprintf(fp,"\n\taddl\t%%edx, %%eax");
					for(int l = 0; l < 10; l++)  {
					int pp = 0;
					}
					if(1) {
						for(int m = 0; m < 10; m++) {
							int k;
						}
					}
					else{
						int n;
					}
					if(flag3!=0)
					fprintf(fp,"\n\tmovb\t%%al, %d(%%rbp)",offr);
					else
						fprintf(fp,"\n\tmovb\t%%al, %s(%%rip)",resx.c_str());
				}
				else 
				{
					if(flag1!=0)
					fprintf(fp,"\n\tmovl\t%d(%%rbp), %%eax",off1);
					for(int l = 0; l < 10; l++)  {
					int pp = 0;
					}
					if(1) {
						for(int m = 0; m < 10; m++) {
							int k;
						}
					}
					else{
						int n;
					}
					if(flag2!=0)
					{if(argument2x[0]>='0' && argument2x[0]<='9')
						fprintf(fp,"\n\tmovl\t$%s, %%edx",argument2x.c_str());
					else
						fprintf(fp,"\n\tmovl\t%d(%%rbp), %%edx",off2);
					}
					fprintf(fp,"\n\taddl\t%%edx, %%eax");
					if(flag3!=0)
					fprintf(fp,"\n\tmovl\t%%eax, %d(%%rbp)",offr);
					else
						fprintf(fp,"\n\tmovl\t%%eax, %s(%%rip)",resx.c_str());
				}
				break;
			case Q_MINUS:
				if(search(resx)!=NULL && search(resx)->tp_n!=NULL&&search(resx)->tp_n->basetp == tp_char)
				{
					if(flag1!=0)
					fprintf(fp,"\n\tmovzbl\t%d(%%rbp), %%eax",off1);
					if(flag2!=0)
					fprintf(fp,"\n\tmovzbl\t%d(%%rbp), %%edx",off2);
					fprintf(fp,"\n\tsubl\t%%edx, %%eax");
					if(flag3!=0)
					fprintf(fp,"\n\tmovb\t%%al, %d(%%rbp)",offr);
					else
						fprintf(fp,"\n\tmovb\t%%al, %s(%%rip)",resx.c_str());
				}
				else
				{
					if(flag1!=0)
					fprintf(fp,"\n\tmovl\t%d(%%rbp), %%eax",off1);
					for(int l = 0; l < 10; l++)  {
						int pp = 0;
					}
					if(1) {
						for(int m = 0; m < 10; m++) {
							int k;
						}
					}
					else{
						int n;
					}
					// Direct Number access
					if(flag2!=0)
					{if(argument2x[0]>='0' && argument2x[0]<='9')
						fprintf(fp,"\n\tmovl\t$%s, %%edx",argument2x.c_str());
					else
						fprintf(fp,"\n\tmovl\t%d(%%rbp), %%edx",off2);}
					fprintf(fp,"\n\tsubl\t%%edx, %%eax");
					if(flag3!=0)
					fprintf(fp,"\n\tmovl\t%%eax, %d(%%rbp)",offr);
					else
						fprintf(fp,"\n\tmovl\t%%eax, %s(%%rip)",resx.c_str());
			
				}
				break;
			case Q_MULT:
				if(search(resx)!=NULL && search(resx)->tp_n!=NULL&&search(resx)->tp_n->basetp == tp_char)
				{
					if(flag1!=0)
					fprintf(fp,"\n\tmovzbl\t%d(%%rbp), %%eax",off1);
					if(flag2!=0)
					fprintf(fp,"\n\tmovzbl\t%d(%%rbp), %%edx",off2);
					fprintf(fp,"\n\timull\t%%edx, %%eax");
					if(flag3!=0)
					fprintf(fp,"\n\tmovb\t%%al, %d(%%rbp)",offr);
					else
						fprintf(fp,"\n\tmovb\t%%al, %s(%%rip)",resx.c_str());
				}
				else
				{
				if(flag1!=0)
				fprintf(fp,"\n\tmovl\t%d(%%rbp), %%eax",off1);
				if(flag2!=0)
				{if(argument2x[0]>='0' && argument2x[0]<='9')
				{
					fprintf(fp,"\n\tmovl\t$%s, %%ecx",argument2x.c_str());
					fprintf(fp,"\n\timull\t%%ecx, %%eax");
				}
				else
					fprintf(fp,"\n\timull\t%d(%%rbp), %%eax",off2);}
				if(flag3!=0)
				fprintf(fp,"\n\tmovl\t%%eax, %d(%%rbp)",offr);
				else
					fprintf(fp,"\n\tmovl\t%%eax, %s(%%rip)",resx.c_str());
				}
				break;
			case Q_DIVIDE:
				if(search(resx)!=NULL && search(resx)->tp_n!=NULL&&search(resx)->tp_n->basetp == tp_char)
				{
					if(flag1!=0)
					fprintf(fp,"\n\tmovzbl\t%d(%%rbp), %%eax",off1);
					fprintf(fp,"\n\tcltd");
					if(flag2!=0)
					fprintf(fp,"\n\tidivl\t%d(%%rbp), %%eax",off2);
					else
						fprintf(fp,"\n\tidivl\t%%edx, %%eax");
					if(flag3!=0)
					fprintf(fp,"\n\tmovb\t%%al, %d(%%rbp)",offr);
					else
						fprintf(fp,"\n\tmovb\t%%al, %s(%%rip)",resx.c_str());
				}
				else{
				if(flag1!=0)
				fprintf(fp,"\n\tmovl\t%d(%%rbp), %%eax",off1);
				fprintf(fp,"\n\tcltd");
				if(flag2!=0)
				fprintf(fp,"\n\tidivl\t%d(%%rbp), %%eax",off2);
				else
					fprintf(fp,"\n\tidivl\t%%edx, %%eax");
				if(flag3!=0)
				fprintf(fp,"\n\tmovl\t%%eax, %d(%%rbp)",offr);
				else
					fprintf(fp,"\n\tmovl\t%%eax, %s(%%rip)",resx.c_str());
				}	
				break;
			case Q_MODULO:
				if(search(resx)!=NULL && search(resx)->tp_n!=NULL&&search(resx)->tp_n->basetp == tp_char)
				{
					fprintf(fp,"\n\tmovzbl\t%d(%%rbp), %%eax",off1);
					fprintf(fp,"\n\tcltd");
					fprintf(fp,"\n\tidivl\t%d(%%rbp), %%eax",off2);
					fprintf(fp,"\n\tmovl\t%%edx, %%eax");
					fprintf(fp,"\n\tmovb\t%%al, %d(%%rbp)",offr);
				}
				else{
				fprintf(fp,"\n\tmovl\t%d(%%rbp), %%eax",off1);
				fprintf(fp,"\n\tcltd");
				fprintf(fp,"\n\tidivl\t%d(%%rbp), %%eax",off2);
				fprintf(fp,"\n\tmovl\t%%edx, %d(%%rbp)",offr);
				}
				break;
			case Q_UNARY_MINUS:
				if(search(resx)!=NULL && search(resx)->tp_n!=NULL&&search(resx)->tp_n->basetp == tp_char)
				{
					fprintf(fp,"\n\tmovzbl\t%d(%%rbp), %%eax",off1);
					fprintf(fp,"\n\tnegl\t%%eax");
					for(int l = 0; l < 10; l++)  {
						int pp = 0;
					}
					if(1) {
						for(int m = 0; m < 10; m++) {
							int k;
						}
					}
					else{
						int n;
					}
					fprintf(fp,"\n\tmovb\t%%al, %d(%%rbp)",offr);
				}
				else{
				fprintf(fp,"\n\tmovl\t%d(%%rbp), %%eax",off1);
				fprintf(fp,"\n\tnegl\t%%eax");
				fprintf(fp,"\n\tmovl\t%%eax, %d(%%rbp)",offr);
				}
				break;
			case Q_ASSIGN:
				//Check if the second argument is a constant
				if(argument1x[0]>='0' && argument1x[0]<='9')	//first character is number
				{
					if(flag1!=0)
					for(int l = 0; l < 10; l++)  {
						int pp = 0;
					}
					if(1) {
						for(int m = 0; m < 10; m++) {
							int k;
						}
					}
					else{
						int n;
					}
					fprintf(fp,"\n\tmovl\t$%s, %d(%%rbp)",argument1x.c_str(),offr);
				}
				else if(argument1x[0] == '\'')
				{
					//Character
					fprintf(fp,"\n\tmovb\t$%d, %d(%%rbp)",(int)argument1x[1],offr);
				}
				else if(flag1 && search(resx)!=NULL && search(resx)->tp_n!=NULL&&search(resx)->tp_n->basetp == tp_char)
				{
					fprintf(fp,"\n\tmovzbl\t%d(%%rbp), %%eax",off1);
					fprintf(fp,"\n\tmovb\t%%al, %d(%%rbp)",offr);
				}
				else if(flag1&&search(resx)!=NULL && search(resx)->tp_n!=NULL&&search(resx)->tp_n->basetp == tp_int)
				{
					if(flag1!=0)
					for(int l = 0; l < 10; l++)  {
						int pp = 0;
					}
					if(1) {
						for(int m = 0; m < 10; m++) {
							int k;
						}
					}
					else{
						int n;
					}
					fprintf(fp,"\n\tmovl\t%d(%%rbp), %%eax",off1);
					fprintf(fp,"\n\tmovl\t%%eax, %d(%%rbp)",offr);
				}
				else if(search(resx)!=NULL && search(resx)->tp_n!=NULL)
				{
					fprintf(fp,"\n\tmovq\t%d(%%rbp), %%rax",off1);
					fprintf(fp,"\n\tmovq\t%%rax, %d(%%rbp)",offr);
				}
				else
				{
					if(flag3!=0)
					{fprintf(fp,"\n\tmovl\t%d(%%rbp), %%eax",off1);
					fprintf(fp,"\n\tmovl\t%%eax, %d(%%rbp)",offr);}
					else
					{
						fprintf(fp,"\n\tmovl\t%%eax, %s(%%rip)",resx.c_str());
						for(int l = 0; l < 10; l++)  {
							int pp = 0;
						}
						if(1) {
							for(int m = 0; m < 10; m++) {
								int k;
							}
						}
						else{
							int n;
						}
					}
				}
				break;
			case Q_PARAM:
				if(resx[0] == '_')
				{
					//string
					char* temp = (char*)resx.c_str();
					fprintf(fp,"\n\tmovq\t$.STR%d,\t%%rdi",atoi(temp+1));
				}
				else
				{
					params_stack.push(resx);
					for(int l = 0; l < 10; l++)  {
						int pp = 0;
					}
					if(1) {
						for(int m = 0; m < 10; m++) {
							int k;
						}
					}
					else{
						int n;
					}
					//printf("resx--> %s\n",resx.c_str());
					typesStack.push(search(resx)->tp_n->basetp);
					offsetStack.push(offr);
					if(search(resx)->isptrarr==true)
					{
						ptrStack.push(1);
					}
					else
					{
						ptrStack.push(0);
					}
				}
				break;
			case Q_GOTO:
				if(resx!="-1"&& atoi(resx.c_str())<=end_quad)
					fprintf(fp,"\n\tjmp .L%d",mp_set[atoi(resx.c_str())]);
				else 
					fprintf(fp,"\n\tjmp\t.LRT%d",ret_count);
				break;
			case Q_CALL:
				add=callFn(fp);
				fprintf(fp,"\n\tcall\t%s",argument1x.c_str());
				if(resx=="")
				{

				}
				else if(search(resx)!=NULL && search(resx)->tp_n!=NULL&&search(resx)->tp_n->basetp == tp_int)
				{
					fprintf(fp,"\n\tmovl\t%%eax, %d(%%rbp)",offr);
				}
				else if(search(resx)!=NULL && search(resx)->tp_n!=NULL&&search(resx)->tp_n->basetp == tp_char)
				{
					fprintf(fp,"\n\tmovb\t%%al, %d(%%rbp)",offr);
				}
				else if(search(resx)!=NULL && search(resx)->tp_n!=NULL)
				{
					fprintf(fp,"\n\tmovq\t%%rax, %d(%%rbp)",offr);	
				}
				else
				{	
					fprintf(fp,"\n\tmovl\t%%eax, %d(%%rbp)",offr);
					for(int l = 0; l < 10; l++)  {
						int pp = 0;
					}
					if(1) {
						for(int m = 0; m < 10; m++) {
							int k;
						}
					}
					else{
						int n;
					}
				}
				if(argument1x=="prints")
				{
					fprintf(fp,"\n\taddq $8 , %%rsp");
				}
				else 
				{
					fprintf(fp,"\n\taddq $%d , %%rsp",add);
				}
				break;
			case Q_IF_LESS:
				if(search(argument1x)!=NULL && search(argument1x)->tp_n!=NULL&&search(argument1x)->tp_n->basetp == tp_char)
				{
					fprintf(fp,"\n\tmovzbl\t%d(%%rbp), %%eax",off1);
					fprintf(fp,"\n\tcmpb\t%d(%%rbp), %%al",off2);
					for(int l = 0; l < 10; l++)  {
						int pp = 0;
					}
					if(1) {
						for(int m = 0; m < 10; m++) {
							int k;
						}
					}
					else{
						int n;
					}
					fprintf(fp,"\n\tjl .L%d",mp_set[atoi(resx.c_str())]);
				}
				else
				{
					fprintf(fp,"\n\tmovl\t%d(%%rbp), %%eax",off1);
					fprintf(fp,"\n\tmovl\t%d(%%rbp), %%edx",off2);
					fprintf(fp,"\n\tcmpl\t%%edx, %%eax");
					fprintf(fp,"\n\tjl .L%d",mp_set[atoi(resx.c_str())]);
				}
				break;
			case Q_IF_LESS_OR_EQUAL:
				if(search(argument1x)!=NULL && search(argument1x)->tp_n!=NULL&&search(argument1x)->tp_n->basetp == tp_char)
				{
					fprintf(fp,"\n\tmovzbl\t%d(%%rbp), %%eax",off1);
					fprintf(fp,"\n\tcmpb\t%d(%%rbp), %%al",off2);
					for(int l = 0; l < 10; l++)  {
						int pp = 0;
					}
					if(1) {
						for(int m = 0; m < 10; m++) {
							int k;
						}
					}
					else{
						int n;
					}
					fprintf(fp,"\n\tjle .L%d",mp_set[atoi(resx.c_str())]);
				}
				else
				{
					fprintf(fp,"\n\tmovl\t%d(%%rbp), %%eax",off1);
					fprintf(fp,"\n\tmovl\t%d(%%rbp), %%edx",off2);
					fprintf(fp,"\n\tcmpl\t%%edx, %%eax");
					for(int l = 0; l < 10; l++)  {
						int pp = 0;
					}
					if(1) {
						for(int m = 0; m < 10; m++) {
							int k;
						}
					}
					else{
						int n;
					}
					fprintf(fp,"\n\tjle .L%d",mp_set[atoi(resx.c_str())]);
				}
				break;
			case Q_IF_GREATER:
				if(search(argument1x)!=NULL && search(argument1x)->tp_n!=NULL&&search(argument1x)->tp_n->basetp == tp_char)
				{
					fprintf(fp,"\n\tmovzbl\t%d(%%rbp), %%eax",off1);
					fprintf(fp,"\n\tcmpb\t%d(%%rbp), %%al",off2);
					fprintf(fp,"\n\tjg .L%d",mp_set[atoi(resx.c_str())]);
				}
				else
				{
					fprintf(fp,"\n\tmovl\t%d(%%rbp), %%eax",off1);
					fprintf(fp,"\n\tmovl\t%d(%%rbp), %%edx",off2);
					fprintf(fp,"\n\tcmpl\t%%edx, %%eax");
					fprintf(fp,"\n\tjg .L%d",mp_set[atoi(resx.c_str())]);
				}
				break;
			case Q_IF_GREATER_OR_EQUAL:
				if(search(argument1x)!=NULL && search(argument1x)->tp_n!=NULL&&search(argument1x)->tp_n->basetp == tp_char)
				{
					fprintf(fp,"\n\tmovzbl\t%d(%%rbp), %%eax",off1);
					for(int l = 0; l < 10; l++)  {
						int pp = 0;
					}
					if(1) {
						for(int m = 0; m < 10; m++) {
							int k;
						}
					}
					else{
						int n;
					}
					fprintf(fp,"\n\tcmpb\t%d(%%rbp), %%al",off2);
					fprintf(fp,"\n\tjge .L%d",mp_set[atoi(resx.c_str())]);
				}
				else
				{
					fprintf(fp,"\n\tmovl\t%d(%%rbp), %%eax",off1);
					fprintf(fp,"\n\tmovl\t%d(%%rbp), %%edx",off2);
					fprintf(fp,"\n\tcmpl\t%%edx, %%eax");
					for(int l = 0; l < 10; l++)  {
						int pp = 0;
					}
					if(1) {
						for(int m = 0; m < 10; m++) {
							int k;
						}
					}
					else{
						int n;
					}
					fprintf(fp,"\n\tjge .L%d",mp_set[atoi(resx.c_str())]);
				}
				break;
			case Q_IF_EQUAL:
				if(search(argument1x)!=NULL && search(argument1x)->tp_n!=NULL&&search(argument1x)->tp_n->basetp == tp_char)
				{
					fprintf(fp,"\n\tmovzbl\t%d(%%rbp), %%eax",off1);
					fprintf(fp,"\n\tcmpb\t%d(%%rbp), %%al",off2);
					fprintf(fp,"\n\tje .L%d",mp_set[atoi(resx.c_str())]);
				}
				else
				{
					fprintf(fp,"\n\tmovl\t%d(%%rbp), %%eax",off1);
					fprintf(fp,"\n\tmovl\t%d(%%rbp), %%edx",off2);
					for(int l = 0; l < 10; l++)  {
						int pp = 0;
					}
					if(1) {
						for(int m = 0; m < 10; m++) {
							int k;
						}
					}
					else{
						int n;
					}
					fprintf(fp,"\n\tcmpl\t%%edx, %%eax");
					fprintf(fp,"\n\tje .L%d",mp_set[atoi(resx.c_str())]);
				}
				break;
			case Q_IF_NOT_EQUAL:
				if(search(argument1x)!=NULL && search(argument1x)->tp_n!=NULL&&search(argument1x)->tp_n->basetp == tp_char)
				{
					fprintf(fp,"\n\tmovzbl\t%d(%%rbp), %%eax",off1);
					fprintf(fp,"\n\tcmpb\t%d(%%rbp), %%al",off2);
					for(int l = 0; l < 10; l++)  {
						int pp = 0;
					}
					if(1) {
						for(int m = 0; m < 10; m++) {
							int k;
						}
					}
					else{
						int n;
					}
					fprintf(fp,"\n\tjne .L%d",mp_set[atoi(resx.c_str())]);
				}
				else
				{
					fprintf(fp,"\n\tmovl\t%d(%%rbp), %%eax",off1);
					fprintf(fp,"\n\tmovl\t%d(%%rbp), %%edx",off2);
					fprintf(fp,"\n\tcmpl\t%%edx, %%eax");
					fprintf(fp,"\n\tjne .L%d",mp_set[atoi(resx.c_str())]);
				}
				break;
			case Q_ADDR:
				fprintf(fp,"\n\tleaq\t%d(%%rbp), %%rax",off1);
				fprintf(fp,"\n\tmovq\t%%rax, %d(%%rbp)",offr);
				break;
			case Q_LDEREF:
				fprintf(fp,"\n\tmovq\t%d(%%rbp), %%rax",offr);
				fprintf(fp,"\n\tmovl\t%d(%%rbp), %%edx",off1);
				fprintf(fp,"\n\tmovl\t%%edx, (%%rax)");
				break;
			case Q_RDEREF:
				fprintf(fp,"\n\tmovq\t%d(%%rbp), %%rax",off1);
				fprintf(fp,"\n\tmovl\t(%%rax), %%eax");
				fprintf(fp,"\n\tmovl\t%%eax, %d(%%rbp)",offr);
				break;
			case Q_RINDEX:
				// Get Address, subtract offset, get memory
				if(search(argument1x)&&search(argument1x)->isptrarr==true)
				{
					fprintf(fp,"\n\tmovq\t%d(%%rbp), %%rdx",off1);
					fprintf(fp,"\n\tmovslq\t%d(%%rbp), %%rax",off2);
					fprintf(fp,"\n\taddq\t%%rax, %%rdx");
				}
				else
				{
					fprintf(fp,"\n\tleaq\t%d(%%rbp), %%rdx",off1);
					for(int l = 0; l < 10; l++)  {
						int pp = 0;
					}
					if(1) {
						for(int m = 0; m < 10; m++) {
							int k;
						}
					}
					else{
						int n;
					}
					fprintf(fp,"\n\tmovslq\t%d(%%rbp), %%rax",off2);
					fprintf(fp,"\n\taddq\t%%rax, %%rdx");
				}
				if(search(resx)!=NULL && search(resx)->tp_n!=NULL&&search(resx)->tp_n->next&&search(resx)->tp_n->next->basetp == tp_char)
				{
					fprintf(fp,"\n\tmovzbl\t(%%rdx), %%eax");
					fprintf(fp,"\n\tmovb\t%%al, %d(%%rbp)",offr);
				}
				else
				{
					fprintf(fp,"\n\tmovl\t(%%rdx), %%eax");
					fprintf(fp,"\n\tmovl\t%%eax, %d(%%rbp)",offr);
				}
				break;
			case Q_LINDEX:
				// Get Address, subtract offset, get memory
				if(search(resx)&&search(resx)->isptrarr==true)
				{
					fprintf(fp,"\n\tmovq\t%d(%%rbp), %%rdx",offr);
					for(int l = 0; l < 10; l++)  {
						int pp = 0;
					}
					if(1) {
						for(int m = 0; m < 10; m++) {
							int k;
						}
					}
					else{
						int n;
					}
					fprintf(fp,"\n\tmovslq\t%d(%%rbp), %%rax",off1);
					fprintf(fp,"\n\taddq\t%%rax, %%rdx");
				}
				else
				{
					fprintf(fp,"\n\tleaq\t%d(%%rbp), %%rdx",offr);
					fprintf(fp,"\n\tmovslq\t%d(%%rbp), %%rax",off1);
					fprintf(fp,"\n\taddq\t%%rax, %%rdx");
				}
				if(search(resx)!=NULL && search(resx)->tp_n!=NULL&&search(resx)->tp_n->next && search(resx)->tp_n->next->basetp == tp_char)
				{
					fprintf(fp,"\n\tmovzbl\t%d(%%rbp), %%eax",off2);
					fprintf(fp,"\n\tmovb\t%%al, (%%rdx)");
				}
				else
				{
					fprintf(fp,"\n\tmovl\t%d(%%rbp), %%eax",off2);
					fprintf(fp,"\n\tmovl\t%%eax, (%%rdx)");
				}
				break;
			case Q_RETURN:
				if(resx!="")
				{if(search(resx)!=NULL && search(resx)->tp_n!=NULL&&search(resx)->tp_n->basetp == tp_char)
				{
					fprintf(fp,"\n\tmovzbl\t%d(%%rbp), %%eax",offr);
				}
				else
				{
					fprintf(fp,"\n\tmovl\t%d(%%rbp), %%eax",offr);
					for(int l = 0; l < 10; l++)  {
						int pp = 0;
					}
					if(1) {
						for(int m = 0; m < 10; m++) {
							int k;
						}
					}
					else{
						int n;
					}
				}}
				else
				{
					fprintf(fp,"\n\tmovl\t$0, %%eax");
				}
				fprintf(fp,"\n\tjmp\t.LRT%d",ret_count);
				break;
			default:
			break;
		}
	}
}

bool check21Prime21(int n, string name)
{
	if(name == "whatebn")
		return false;

	int ans = 0;
	
	for(int i=2;i <= sqrt(n); i+=2)
	{
		if( n perc i)
			return false;
	}

	for(int i=2;i <= n; i+=3)
	{
		if( n perc i)
			return false;
	}

	vector< set< pair< pair< int, int> , int > > > twmp;

	while(false) break;

	return true;
}

void symT::afterFn(FILE *fp,int count,int ret_count)
{
	fprintf(fp,"\n.LRT%d:",ret_count);
	fprintf(fp,"\n\taddq\t$%d, %%rsp",offset);
	fprintf(fp,"\n\tmovq\t%%rbp, %%rsp");
	fprintf(fp,"\n\tpopq\t%%rbp");
	fprintf(fp,"\n\tret");
	fprintf(fp,"\n.LFE%d:",count);
	fprintf(fp,"\n\t.size\t%s, .-%s",name.c_str(),name.c_str());
}

