#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <stdc++.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <locale>
#include <math.h>
using namespace std;
int flag=0;

void my_google()
{
	string s="googler";
  	char *p=new char[s.size()];
  	for(int i=0;i<s.size();++i) p[i]=s[i];
  	system(p);
}
void function_mkdir(char* name)
{
    int stat = mkdir(name, 0777);// all appropriate permissions
    if(stat==-1)
    {
        perror("Sorry! ");
        cout<<endl;
    }
    else
    {
    	printf("Success!,folder created");
    	cout<<endl;
    }
}
bool cmp(string &a,string &b)
{
	string s=a;
	string t=b;
	locale loc;
	for(int i=0; i<s.size(); ++i)
	    s[i]=tolower(s[i],loc);
	for(int i=0; i<t.size(); ++i)
	    t[i]=tolower(t[i],loc);
	if(s.compare(t)<0)
		return true;
	else
		return false;
}
void replace(char t[],int l)
{
	int flag=0;
	for(int i=strlen(t)-1;i>=0;i--)
	{
		if(t[i]=='/')
		{
			flag=i;
			break;
		}
	}
	t[flag]='\0';
}

void about()
{
    // Source - http://ascii.co.uk/art/seashell
    string descr = "           _.-''|''-._\n        .-'     |     `-.\n      .'\\       |       /`.\n    .'   \\      |      /   `.        \n    \\     \\     |     /     /         \tMINT SHELL \n     `\\    \\    |    /    /'\t Made by Archit Saksham Harsh Mukul\n       `\\   \\   |   /   /'\n         `\\  \\  |  /  /'\n        _.-`\\ \\ | / /'-._ \n       {_____`\\\\|//'_____}\n               `-'\n\n";

   cout<<descr<<endl;
}
int main(int argc, char** argv)
{
	about();
    char enter = (char)13;
    cout<<enter;
    char cur_folder[1024];
    getcwd(cur_folder, 1024);
	char input[1024];
    int flag11=0;
	char help[5];
	while(strcmp(input,"exit")!=0)
	{
		cout<<endl<<endl;
		 cout<<"1. create a new file : new_file"<<endl;
            cout<<"2. add data on a file : add_data"<<endl;
            cout<<"3. to read file : read_file"<<endl;
            cout<<"4. to delete a file : delete_file"<<endl;
            cout<<"5. to create a new folder : new_folder"<<endl;
            cout<<"6. Google anything : google "<<endl;
            cout<<"7. list directories : list_dir"<<endl;
            cout<<"8. to go back in a directory : back"<<endl;
            cout<<"9. open folder : open_folder"<<endl;
            cout<<"10. calculator : calculator"<<endl;
            cout<<endl<<endl; 
		 if(flag11==0)
        {
            printf("Welcome to my terminal \n");
            cout<<"If you're knew to this terminal, want help? type help else type anything ";
            cin>>help;
        }

        int choice;
        if(strcmp(help,"help")==0 || strcmp(help,"HELP")==0)
        {
            flag=0;
            cout<<"Enter your choice: "; cin>>choice;
             switch(choice)
            {
                case 1: cout<<"Step1: type new_file on terminal"<<endl;
                        cout<<"Step2: enter the name of file to be created"<<endl;
                        break;
                case 2: cout<<"Step1: type add_data on terminal"<<endl;
                        cout<<"Step2: enter the filename of the file on which you want to add data"<<endl;
                        cout<<"Step3:  enter your data"<<endl;
                        cout<<"Step4: enter '~~' to end addind data"<<endl;
                        break;
                case 3: cout<<"Step1: type read_file on terminal"<<endl;
                        cout<<"Step2:  enter the name of file"<<endl;
                        break;
                case 4: cout<<"Step1: type delete_file on terminal"<<"\n";
                        cout<<"Step2: type the name of the file"<<"\n";
                        break;
                
                case 5: cout<<"Step1: type new_folder on terminal\n";
                        cout<<"Step2: enter the folder name\n";
                        break;
                case 6: cout<<"Step1: type open_folder on terminal\n";
                        cout<<"Step2: enter the name of the folder\n";
                        break;
                case 7: cout<<"Step1: type google on terminal\n";
                        cout<<"Step2: enter anything you want to google\n";
                        break;
                case 8: cout<<"Step1: type list_dir on terminal\n";
                        break;
                case 9: cout<<"Step1: type back on terminal\n";
                        break;
                case 10: cout<<"Step1: type calculator on terminal"<<"\n";
                        cout<<"Step2: enter the operation you want to perform"<<endl;
                        cout<<"operations available are"<<endl<<"'add' for addition"<<endl;
                        cout<<"'sub': for subtraction"<<endl<<"'mul' for multiply"<<endl<<"'div' for division";
                        cout<<endl<<"'mod' for modulus"<<endl<<"'power' for power"<<endl;
                        cout<<"Step3: enter the two operands"<<endl;
                        cout<<"Step4: type any character to exit operation"<<endl;
                        cout<<"Step4: type exit to exit calculator"<<endl;
                        break;
            }
        }
        else
        {
        	flag11=1;
        	printf("%s -> ",cur_folder);
        	scanf("%s",input);
        
		if(strcmp(input,"new_file")==0)
		{
			char s[1000];
			cin>>s;
			if(fopen(s,"r")!=NULL)
			{
				cout<<"File already exists\n";
			}
			else
			{
				fopen(s,"w");
				cout<<"File created Successfully \n";
			}
		}
		if(strcmp(input,"add_data")==0)
		{
			FILE *fp;
		    char source[1024];
		    scanf("%s",source);
		    fp=fopen(source,"a");
			cout<<"Enter Data to be added(enter ~~ to end adding data)"<<endl;
			char s[100];
			cin>>s;
			while(strcmp(s,"~~")!=0)
			{
				fprintf(fp,"%s ",s);
				cin>>s;
			}
			fclose(fp);
		}
		if(strcmp(input,"read_file")==0)
    	{
		    FILE *fp;
		    char source[1024];
		    scanf("%s",source);
		    fp=fopen(source,"r");
			char c;
			while(!feof(fp))
			{
				fscanf(fp,"%c",&c);
				printf("%c",c);
			}
			printf("\n");
		}
		if(strcmp(input,"delete_file")==0)
		{
			char ch[1024];
			scanf("%s",ch);
			if(!remove(ch))
			{
				printf("File removed");
				printf("\n");
			}
			else
			{
				printf("No such file exists\n");
			}
		}
		if(strcmp(input,"list_dir")==0)
        {
            DIR *dire;
            struct dirent *dir;
            dire=opendir(cur_folder);
            if(dire)
            {
                vector<string>files;vector<string>::iterator it;
                while((dir=readdir(dire))!=NULL)
                    files.push_back(dir->d_name);
                for(it=files.begin();it!=files.end();it++)
                    cout<<(*it)<<"\n";
                printf("\n");
                closedir(dire);
            }
        }
        if(strcmp(input,"back")==0)
        {
            flag=0;
            int count=0;
            //cout<<strlen(cur_folder)<<endl;
            for(int i=0;i<strlen(cur_folder);i++)
            {
                if(cur_folder[i]=='/')
                {
                    count++;
                }
            }
            if(count>=1)
            {
                replace(cur_folder,0);
            }
            continue;
        }
		if(strcmp(input,"open_folder")==0)
		{
			char ch[1024];
			scanf("%s",ch);
			struct stat sb;
			char ch2[1024];
			strcpy(ch2,cur_folder);
			strcat(ch2,"/");
			strcat(ch2,ch);
			const char *t=ch2;
			if(stat(t, &sb) == 0 && S_ISDIR(sb.st_mode))
	 		{
	       		strcpy(cur_folder,ch2);
		    }
	   		else
	   		{
                printf("Directory Not Exists\n");
    		}
		}
		if(strcmp(input,"new_folder")==0)
		{
			char name;
			scanf("%s",&name);
			function_mkdir(&name);
		}
     	if(strcmp(input,"calculator")==0)
		{
	   		cout<<"Enter the operation you want to perform"<<endl;
	   		char ch[100];
	 		do
	 		{
	  			scanf("%s",ch);

			    vector <int> myv;
			    int num,sum=0,mul=1,count=0;
			    float div=1.0;
			    
			   	if(strcmp(ch,"add")==0)
			   	{
			   		cout<<"to stop entering data enter any character"<<endl;
			    	while(scanf("%d",&num))
			    	{
			            myv.push_back(num);
	                }
			     	for(int i=0;i<myv.size();i++)
			        sum=sum+myv[i];
			    	cout<<"Ans "<<sum<<endl;
			    }
			   	else if(strcmp(ch,"sub")==0)
			   	{
			   		cout<<"to stop entering data enter any character"<<endl;
			     	while(scanf("%d",&num))
			        	myv.push_back(num);
			        sum=myv[0];
			     	for(int i=1;i<myv.size();i++)
			     	{
			            sum=sum-myv[i];
			     	}

			    	cout<<"Ans "<<sum<<endl;
				}
	   			else if(strcmp(ch,"mul")==0)
	   			{
	   				cout<<"to stop entering data enter any character"<<endl;
	     			while(scanf("%d",&num))
	             		myv.push_back(num);

	     			for(int i=0;i<myv.size();i++)
	             		mul=mul*myv[i];
	    			cout<<"Ans "<<mul<<endl;
	    		}
	   			else if(strcmp(ch,"div")==0)
	   			{
	   				cout<<"to stop entering data enter any character"<<endl;
	    			while(scanf("%d",&num))
	             		myv.push_back(num);

	     			for(int i=0;i<myv.size();i++)
	     			{
	             		if(i==0)
	             			div=myv[i];
	             		else
	             			div=float(div/myv[i]*1.0);
	         		}
	    			cout<<"Ans "<<div<<endl;
	    		}
	   			else if(strcmp(ch,"mod")==0)
	   			{

	     			while(count<2)
	     			{
	     				scanf("%d",&num);
	     				count++;
	             		myv.push_back(num);
	                }
	     			if(count==2)
	     			{
	     				float mod=myv[0]%myv[1];
	    				cout<<"Ans "<<mod<<endl;
	    				count=0;
	    			}
	   				else
	   					cout<<"Only 2 Num required for modulos"<<endl;
	       		}
	     		else if(strcmp(ch,"power")==0)
	     		{
	     			while(count<2)
	     			{
	     				scanf("%d",&num);
	     				count++;
	             		myv.push_back(num);
	                }
	     			if(count==2)
	     			{
	     				float mod=pow(myv[0],myv[1]);
	    				cout<<"Ans "<<mod<<endl;
	    				count=0;
	    			}
	   				else
	   					cout<<"Only 2 Num required for power"<<endl;
	           	}
	   			else if(strcmp(ch,"exit")==0)
	   				cout<<"exiting calculator..."<<endl;

			}while(strcmp(ch,"exit")!=0);
  		}
  		if(strcmp(input,"google")==0)
			my_google();

	}

  	}
	return 0;
}
