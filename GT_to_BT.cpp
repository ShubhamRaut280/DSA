#include <iostream>

using namespace std;

//Binary Tree node
class Node
{
    private:
        string title;
        Node *left;  //Pointer to first or only child in General Tree
        Node *right; //Pointer to right sibling;
    public:
        Node(string title = "null")
        {
            this->title = title;
            this->left = NULL;
            this->right = NULL;
        }
        void display()
        {
            cout<<this->title;
        }
friend class Binary_Tree;
};

class Binary_Tree
{
    private:
        Node * root;
    public:
        Binary_Tree()
        {
            root = NULL;
        }
        Binary_Tree(string title)
        {
            root = new Node(title);
        }
        void display()
        {
            if(root == NULL)
            {
                cout<<"Empty Book Record"<<endl;
                return;
            }

            cout<<"Book Record for -> "<<root->title<<endl;
            preOrder(root);
        }
        Node * findChapter();
        void addChapter(string chapter_name);
        void addSection(string chapter_name, string section_name);
        void addSubSection(string chapter_name, string section_name,string sub_section_name);
        void preOrder(Node *root);
        Node * SearchLast(Node *start);
        Node *Search(Node *start, string title);
};

Node * Binary_Tree::Search(Node *start, string title)
{
    Node *last;
    last = start;
        if(last == NULL) //Not Present
        {
          return NULL;
        }
        else
        {
            while(last!= NULL)
            {
                if(last->title==title)
                {//found
                    return last;
                }
                last = last->right;
            }
            return NULL;
        }
}
Node * Binary_Tree::SearchLast(Node *start)
{
    Node *cur;
    cur = start;
    while(cur->right != NULL)
    {
        cur = cur->right;
    }
    return cur;
}

void Binary_Tree::preOrder(Node *root)
{
    if(root!=NULL)
    {
        cout<<root->title<<endl;
        preOrder(root->left);
        preOrder(root->right);
    }
}
void Binary_Tree::addChapter(string chapter_name)
{
    if(root == NULL)
    {
        cout<<"Empty Book Record ---: Failed to add chapter "<<endl;
        return;
    }
    else
    {
        Node *lastChapter = NULL,*Chapter;
        Chapter = root->left;   //First chapter is in the left of root

        if(Chapter == NULL) //Add First Chapter
        {
            root->left = new Node(chapter_name);
            cout<<chapter_name<<" First chapter in the book "<<root->title<<" added successfully "<<endl;
        }
        else
        {
            Chapter = Search(Chapter,chapter_name);
            if (Chapter == NULL ) //Chapter not present add in the last
            {
                lastChapter = SearchLast(Chapter); //Chapter is Not present so adding in the last position in the Book
                lastChapter->right = new Node(chapter_name);
                cout<<chapter_name<<" Chapter in the book "<<root->title<<" added successfully as a last chapter"<<endl;
            }
            else
            {
                cout<<"Error : Failed to add Chapter...duplicate chapter name"<<endl;
            }
        }
    }
}


void Binary_Tree::addSection(string chapter_name, string section_name)
{
    if(root == NULL)
    {
        cout<<"Empty Book Record ---: Failed to add Section"<<endl;
        return;
    }
    else
    {
        Node *Chapter,*Section,*lastSection;
        Chapter = root->left;   //First chapter is in the left of root
        if(Chapter == NULL) //Chapter Not added
        {
             cout<<"No Chapters Present---: Failed to add Section "<<endl;
             return;
        }
        else
         {  //Search Chapter
            Chapter = Search(root->left,chapter_name);
            if (Chapter == NULL ) //Chapter not present addition of section failed
            {
                cout<<"Error : Failed to add Section...chapter name not found"<<endl;
            }
            else
            {   //Chapter Found
                Section = Chapter->left;
                if(Section == NULL)  //Adding First Section
                  {
                      Chapter->left = new Node(section_name);
                      cout<<section_name<<" First section in the chapter "<<Chapter->title<<" added successfully "<<endl;
                  }
                  else
                  {
                    Section = Search(Section,section_name);
                    if(Section == NULL)
                    {
                        lastSection = SearchLast(Chapter->left); //Chapter is Not present so adding in the last position in the Book
                        lastSection->right = new Node(section_name);
                        cout<<section_name<<" section in the chapter "<<chapter_name<<" added successfully as a last section"<<endl;
                    }
                    else
                    {
                        cout<<"Error: Duplicate section name ";
                    }
                  }
            }
        }
    }
}
void Binary_Tree::addSubSection(string chapter_name, string section_name,string sub_section_name)
{

if(root == NULL)
    {
        cout<<"Empty Book Record ---: Failed to add Sub - Section"<<endl;
        return;
    }
    else
    {
        Node *Chapter,*Section,*subSection,*lastSubSection;
        Chapter = root->left;   //First chapter is in the left of root
        if(Chapter == NULL) //Chapter Not added
        {
             cout<<"No Chapters Present---: Failed to add Sub - Section "<<endl;
             return;
        }
        else
         {  //Search Chapter
            Chapter = Search(Chapter,chapter_name);
            if (Chapter == NULL ) //Chapter not present addition of section failed
            {
                cout<<"Error : Failed to add Sub - Section...chapter name "<<chapter_name<<" not found"<<endl;
                return;
            }
            else
            {   //Chapter Found
                Section = Chapter->left; //Sections are in first chapter's left
                if(Section == NULL)  //Adding First Section
                  {
                      cout<<"Error : Failed to add Sub - Section...No Sections added in chapter "<<chapter_name<< " yet "<<endl;
                      return;
                  }
                  else
                  {
                    Section = Search(Section,section_name);
                    if(Section == NULL)
                    {
                        cout<<"Error : Failed to add Sub - Section...Section"<<section_name<<" not found "<<endl;
                        return;
                    }
                    else
                    {   //Section found
                        subSection = Section->left; //subsection are in section left
                        if(subSection == NULL) //Adding first sub section
                        {
                            Section->left = new Node(sub_section_name);
                            cout<<sub_section_name<<" First Sub - Section in the Section "<<section_name<<" of "<<chapter_name<<" added successfully "<<endl;
                        }
                        else
                        {
                                subSection = Search(subSection,sub_section_name);
                                if(subSection == NULL)
                                {
                                    lastSubSection = SearchLast(Section->left); //SubSecetion is Not present so adding in the last position in the Book
                                    lastSubSection->right = new Node(sub_section_name);
                                    cout<<sub_section_name<<" sub section in the section "<<section_name<<" of chapter" <<chapter_name<<" added successfuslly as a last section"<<endl;
                                }
                                else
                                {
                                    cout<<"Error: Duplicate sub section name ";
                                }
                        }

                    }
                  }
            }
        }
    }
}
int main()
{
    string book_name;
    cout<<"Enter the Book Name  : ";cin>>book_name;
    Binary_Tree b(book_name);

    string chapter_name,section_name,subsection_name;
    int choice;
    do{
        cout<<"***** M E N U *****"<<endl;
        cout<<"1. Add Chapter    "<<endl
            <<"2. Add Section    "<<endl
            <<"3. Add Sub-Section"<<endl
            <<"4. Display        "<<endl
            <<"5. Exit           "<<endl
            ;
        cout<<"Enter your choice : ";cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter Chapter Name ";cin>>chapter_name;
            b.addChapter(chapter_name);
            break;
        case 2:
            cout<<"Enter Chapter Name ";cin>>chapter_name;
            cout<<"Enter Section Name ";cin>>section_name;
            b.addSection(chapter_name,section_name);
            break;
        case 3:
            cout<<"Enter Chapter Name ";cin>>chapter_name;
            cout<<"Enter Section Name ";cin>>section_name;
            cout<<"Enter Sub-Section Name ";cin>>subsection_name;
            b.addSubSection(chapter_name,section_name,subsection_name);
            break;
        case 4:
            b.display();
            break;
        default:
            cout<<"Enter choice between 1..5"<<endl;
        }

    }while(choice != 5);

return 0;
}