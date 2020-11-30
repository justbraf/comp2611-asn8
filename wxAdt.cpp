#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
    #include <wx/spinctrl.h>
#endif

#include "dialogBox.h"
#include "removeDialogBox.h"
#include "Queue.h"
#include "PQueue.h"
#include "Stack.h"
#include "Deque.h"
#include "BSTree.h"
#include "AVLTree.h"
#include "MinHeap.h"
#include "RBT.h"
#include <fstream>


struct rec {
     int rank;
     char name[20];
     char nationality[20];
     int score;
     char opponent[15];
     int year;
};

// Global pointers for the ADT containers
Queue* dataQ = new Queue();
PQueue* dataPQ = new PQueue();
Stack* dataStack = new Stack();
Deque* dataDQ = new Deque();
BSTree* dataBST = new BSTree();
AVLTree* dataAVL = new AVLTree();
MinHeap* dataMH = new MinHeap();

class AdtApp: public wxApp{
    // application to start
    virtual bool OnInit();
};

class AdtFrame: public wxFrame{
    private:
        // event handling
        DECLARE_EVENT_TABLE()
    public:
        // constructor
        AdtFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

        // event handlers for menus

        // file menu
        void OnOpen(wxCommandEvent& event);
        void OnSave(wxCommandEvent& event);
        void OnSaveAs(wxCommandEvent& event);
        void OnExit(wxCommandEvent& event);
        //display menu
        void OnDisplayFile(wxCommandEvent& event);
        // Queue menu
        void OnCreateQueue(wxCommandEvent& event);
        void OnAddData(wxCommandEvent& event);
        void OnDisplayAllQ(wxCommandEvent& event);
        void OnShowHeadQ(wxCommandEvent& event);
        void OnShowTailQ(wxCommandEvent& event);
        void OnDequeue(wxCommandEvent& event);
        // Deque menu
        void OnCreateDeque(wxCommandEvent& event);
        void OnAddHead(wxCommandEvent& event);
        void OnAddTail(wxCommandEvent& event);
        void OnDisplayAllD(wxCommandEvent& event);
        void OnShowHeadD(wxCommandEvent& event);
        void OnShowTailD(wxCommandEvent& event);
        void OnDequeueHead(wxCommandEvent& event);
        void OnDequeueTail(wxCommandEvent& event);
        // Priority Queue menu
        void OnCreatePQ(wxCommandEvent& event);
        void OnAddDataPQ(wxCommandEvent& event);
        void OnDisplayAllPQ(wxCommandEvent& event);
        void OnShowHeadPQ(wxCommandEvent& event);
        void OnShowTailPQ(wxCommandEvent& event);
        void OnDequeuePQ(wxCommandEvent& event);
        // Stack menu
        void OnCreateStack(wxCommandEvent& event);
        void OnPop(wxCommandEvent& event);
        void OnPush(wxCommandEvent& event);
        void OnDisplayAllS(wxCommandEvent& event);
        // BST menu
        void OnCreateBST(wxCommandEvent& event);
        void OnAddDataBST(wxCommandEvent& event);
        void OnDeleteDataBST(wxCommandEvent& event);
        void OnInorderBST(wxCommandEvent& event);
        void OnPreorderBST(wxCommandEvent& event);
        void OnPostorderBST(wxCommandEvent& event);
        // AVL Tree menu
        void OnCreateAVL(wxCommandEvent& event);
        void OnAddDataAVL(wxCommandEvent& event);
        void OnDeleteDataAVL(wxCommandEvent& event);
        void OnInorderAVL(wxCommandEvent& event);
        void OnPreorderAVL(wxCommandEvent& event);
        void OnPostorderAVL(wxCommandEvent& event);
        // Heap menu
        void OnCreateHeap(wxCommandEvent& event);
        void OnAddDataHeap(wxCommandEvent& event);
        void OnDeleteDataHeap(wxCommandEvent& event);
        void OnDisplayAllHeap(wxCommandEvent& event);
        void OnHeapSort(wxCommandEvent& event);
        // RB Tree menu
        void OnCreateRB(wxCommandEvent& event);
        void OnAddDataRB(wxCommandEvent& event);
        void OnDeleteDataRB(wxCommandEvent& event);
        void OnInorderRB(wxCommandEvent& event);
        void OnPreorderRB(wxCommandEvent& event);
        void OnPostorderRB(wxCommandEvent& event);
        // Splay menu
        void OnCreateSplay(wxCommandEvent& event);
        void OnAddDataSplay(wxCommandEvent& event);
        void OnDeleteDataSplay(wxCommandEvent& event);
        void OnInorderSplay(wxCommandEvent& event);
        void OnPreorderSplay(wxCommandEvent& event);
        void OnPostorderSplay(wxCommandEvent& event);
        // Set menu
        void OnCreateSets(wxCommandEvent& event);
        void OnAddDataSets(wxCommandEvent& event);
        void OnDisplaySetA(wxCommandEvent& event);
        void OnDisplaySetB(wxCommandEvent& event);
        void OnDisplayIn(wxCommandEvent& event);
        void OnDisplayUn(wxCommandEvent& event);
        void OnDeleteSetA(wxCommandEvent& event);
        void OnDeleteSetB(wxCommandEvent& event);
        // Help menu
        void OnAbout(wxCommandEvent& event);

        // Public attributes
        wxTextCtrl* mainEditBox;
        wxTextCtrl* fileNameTextBox;
        wxString currentFilePath;
};

// declare application class
DECLARE_APP(AdtApp)
// create application class object
IMPLEMENT_APP(AdtApp)

enum{
    // File menu
    ID_Open = wxID_HIGHEST + 1,
    ID_Save = wxID_HIGHEST + 2,
    ID_SaveAs = wxID_HIGHEST + 3,
    ID_Quit = wxID_HIGHEST + 4,
    // Display menu
    ID_DisplayFile = wxID_HIGHEST + 5,
    // Queue menu
    ID_CreateQueue = wxID_HIGHEST + 6,
    ID_AddData = wxID_HIGHEST + 7,
    ID_DisplayAllQ = wxID_HIGHEST + 8,
    ID_ShowHeadQ = wxID_HIGHEST + 9,
    ID_ShowTailQ = wxID_HIGHEST + 10,
    ID_Dequeue = wxID_HIGHEST + 11,
    // Deque menu
    ID_CreateDeque = wxID_HIGHEST + 12,
    ID_AddHead = wxID_HIGHEST + 13,
    ID_AddTail = wxID_HIGHEST + 14,
    ID_DisplayAllD = wxID_HIGHEST + 15,
    ID_ShowHeadD = wxID_HIGHEST + 16,
    ID_ShowTailD = wxID_HIGHEST + 17,
    ID_DequeueHead = wxID_HIGHEST + 18,
    ID_DequeueTail = wxID_HIGHEST + 19,
    // Priority Queue menu
    ID_CreatePQ = wxID_HIGHEST + 20,
    ID_AddDataPQ = wxID_HIGHEST + 21,
    ID_DisplayAllPQ = wxID_HIGHEST + 22,
    ID_ShowHeadPQ = wxID_HIGHEST + 23,
    ID_ShowTailPQ = wxID_HIGHEST + 24,
    ID_DequeuePQ = wxID_HIGHEST + 25,
    // Stack menu
    ID_CreateStack = wxID_HIGHEST + 26,
    ID_Pop = wxID_HIGHEST + 27,
    ID_Push = wxID_HIGHEST + 28,
    ID_DisplayAllS = wxID_HIGHEST + 29,
    // BST menu
    ID_CreateBST = wxID_HIGHEST + 30,
    ID_AddDataBST = wxID_HIGHEST + 31,
    ID_DeleteDataBST = wxID_HIGHEST + 32,
    ID_InorderBST = wxID_HIGHEST + 33,
    ID_PreorderBST = wxID_HIGHEST + 34,
    ID_PostorderBST = wxID_HIGHEST + 35,
    // AVL menu
    ID_CreateAVL = wxID_HIGHEST + 36,
    ID_AddDataAVL = wxID_HIGHEST + 37,
    ID_DeleteDataAVL = wxID_HIGHEST + 38,
    ID_InorderAVL = wxID_HIGHEST + 39,
    ID_PreorderAVL = wxID_HIGHEST + 40,
    ID_PostorderAVL = wxID_HIGHEST + 41,
    // Heap menu
    ID_CreateHeap = wxID_HIGHEST + 42,
    ID_AddDataHeap = wxID_HIGHEST + 43,
    ID_DeleteDataHeap = wxID_HIGHEST + 44,
    ID_DisplayAllHeap = wxID_HIGHEST + 45,
    ID_HeapSort = wxID_HIGHEST + 46,
    // RB menu
    ID_CreateRB = wxID_HIGHEST + 47,
    ID_AddDataRB = wxID_HIGHEST + 48,
    ID_DeleteDataRB = wxID_HIGHEST + 49,
    ID_InorderRB = wxID_HIGHEST + 50,
    ID_PreorderRB = wxID_HIGHEST + 51,
    ID_PostorderRB = wxID_HIGHEST + 52,
    // Splay menu
    ID_CreateSplay = wxID_HIGHEST + 53,
    ID_AddDataSplay = wxID_HIGHEST + 54,
    ID_DeleteDataSplay = wxID_HIGHEST + 55,
    ID_InorderSplay = wxID_HIGHEST + 56,
    ID_PreorderSplay = wxID_HIGHEST + 57,
    ID_PostorderSplay = wxID_HIGHEST + 58,
    // Set menu
    ID_CreateSets = wxID_HIGHEST + 59,
    ID_AddDataSets = wxID_HIGHEST + 60,
    ID_DisplaySetA = wxID_HIGHEST + 61,
    ID_DisplaySetB = wxID_HIGHEST + 62,
    ID_DisplayIn = wxID_HIGHEST + 63,
    ID_DisplayUn = wxID_HIGHEST + 64,
    ID_DeleteSetA = wxID_HIGHEST + 65,
    ID_DeleteSetB = wxID_HIGHEST + 66,
    // Help menu
    ID_About = wxID_HIGHEST + 67
};

BEGIN_EVENT_TABLE(AdtFrame, wxFrame)
    // File menu identifiers
    EVT_MENU(ID_Open, AdtFrame::OnOpen)
    EVT_MENU(ID_Save, AdtFrame::OnSave)
    EVT_MENU(ID_SaveAs, AdtFrame::OnSaveAs)
    EVT_MENU(ID_Quit, AdtFrame::OnExit)
    // Display menu idetifiers
    EVT_MENU(ID_DisplayFile, AdtFrame::OnDisplayFile)
    // Queue menu identifiers
    EVT_MENU(ID_CreateQueue, AdtFrame::OnCreateQueue)
    EVT_MENU(ID_AddData, AdtFrame::OnAddData)
    EVT_MENU(ID_DisplayAllQ, AdtFrame::OnDisplayAllQ)
    EVT_MENU(ID_ShowHeadQ, AdtFrame::OnShowHeadQ)
    EVT_MENU(ID_ShowTailQ, AdtFrame::OnShowTailQ)
    EVT_MENU(ID_Dequeue, AdtFrame::OnDequeue)
    // Deque menu identifiers
    EVT_MENU(ID_CreateDeque, AdtFrame::OnCreateDeque)
    EVT_MENU(ID_AddHead, AdtFrame::OnAddHead)
    EVT_MENU(ID_AddTail, AdtFrame::OnAddTail)
    EVT_MENU(ID_DisplayAllD, AdtFrame::OnDisplayAllD)
    EVT_MENU(ID_ShowHeadD, AdtFrame::OnShowHeadD)
    EVT_MENU(ID_ShowTailD, AdtFrame::OnShowTailD)
    EVT_MENU(ID_DequeueHead, AdtFrame::OnDequeueHead)
    EVT_MENU(ID_DequeueTail, AdtFrame::OnDequeueTail)
    // Priority Queue identifiers
    EVT_MENU(ID_CreatePQ, AdtFrame::OnCreatePQ)
    EVT_MENU(ID_AddDataPQ, AdtFrame::OnAddDataPQ)
    EVT_MENU(ID_DisplayAllPQ, AdtFrame::OnDisplayAllPQ)
    EVT_MENU(ID_ShowHeadPQ, AdtFrame::OnShowHeadPQ)
    EVT_MENU(ID_ShowTailPQ, AdtFrame::OnShowTailPQ)
    EVT_MENU(ID_DequeuePQ, AdtFrame::OnDequeuePQ)
    // Stack menu identifiers
    EVT_MENU(ID_CreateStack, AdtFrame::OnCreateStack)
    EVT_MENU(ID_Pop, AdtFrame::OnPop)
    EVT_MENU(ID_Push, AdtFrame::OnPush)
    EVT_MENU(ID_DisplayAllS, AdtFrame::OnDisplayAllS)
    // BST menu identifiers
    EVT_MENU(ID_CreateBST, AdtFrame::OnCreateBST)
    EVT_MENU(ID_AddDataBST, AdtFrame::OnAddDataBST)
    EVT_MENU(ID_DeleteDataBST, AdtFrame::OnDeleteDataBST)
    EVT_MENU(ID_InorderBST, AdtFrame::OnInorderBST)
    EVT_MENU(ID_PreorderBST, AdtFrame::OnPreorderBST)
    EVT_MENU(ID_PostorderBST, AdtFrame::OnPostorderBST)
    // AVL menu identifiers
    EVT_MENU(ID_CreateAVL, AdtFrame::OnCreateAVL)
    EVT_MENU(ID_AddDataAVL, AdtFrame::OnAddDataAVL)
    EVT_MENU(ID_DeleteDataAVL, AdtFrame::OnDeleteDataAVL)
    EVT_MENU(ID_InorderAVL, AdtFrame::OnInorderAVL)
    EVT_MENU(ID_PreorderAVL, AdtFrame::OnPreorderAVL)
    EVT_MENU(ID_PostorderAVL, AdtFrame::OnPostorderAVL)
    // Heap menu identifiers
    EVT_MENU(ID_CreateHeap, AdtFrame::OnCreateHeap)
    EVT_MENU(ID_AddDataHeap, AdtFrame::OnAddDataHeap)
    EVT_MENU(ID_DeleteDataHeap, AdtFrame::OnDeleteDataHeap)
    EVT_MENU(ID_DisplayAllHeap, AdtFrame::OnDisplayAllHeap)
    EVT_MENU(ID_HeapSort, AdtFrame::OnHeapSort)
    // RB menu identifiers
    EVT_MENU(ID_CreateRB, AdtFrame::OnCreateRB)
    EVT_MENU(ID_AddDataRB, AdtFrame::OnAddDataRB)
    EVT_MENU(ID_DeleteDataRB, AdtFrame::OnDeleteDataRB)
    EVT_MENU(ID_InorderRB, AdtFrame::OnInorderRB)
    EVT_MENU(ID_PreorderRB, AdtFrame::OnPreorderRB)
    EVT_MENU(ID_PostorderRB, AdtFrame::OnPostorderRB)
    // Splay menu identifiers
    EVT_MENU(ID_CreateSplay, AdtFrame::OnCreateSplay)
    EVT_MENU(ID_AddDataSplay, AdtFrame::OnAddDataSplay)
    EVT_MENU(ID_DeleteDataSplay, AdtFrame::OnDeleteDataSplay)
    EVT_MENU(ID_InorderSplay, AdtFrame::OnInorderSplay)
    EVT_MENU(ID_PreorderSplay, AdtFrame::OnPreorderSplay)
    EVT_MENU(ID_PostorderSplay, AdtFrame::OnPostorderSplay)
    // Set menu identifiers
    EVT_MENU(ID_CreateSets, AdtFrame::OnCreateSets)
    EVT_MENU(ID_AddDataSets, AdtFrame::OnAddDataSets)
    EVT_MENU(ID_DisplaySetA, AdtFrame::OnDisplaySetA)
    EVT_MENU(ID_DisplaySetB, AdtFrame::OnDisplaySetB)
    EVT_MENU(ID_DisplayIn, AdtFrame::OnDisplayIn)
    EVT_MENU(ID_DisplayUn, AdtFrame::OnDisplayUn)
    EVT_MENU(ID_DeleteSetA, AdtFrame::OnDeleteSetA)
    EVT_MENU(ID_DeleteSetB, AdtFrame::OnDeleteSetB)
    // Help menu identifiers
    EVT_MENU(ID_About, AdtFrame::OnAbout)
END_EVENT_TABLE()

bool AdtApp::OnInit(){
    // create the main application window
    AdtFrame *frame = new AdtFrame("COMP2611 - Data Structures", wxPoint(100, 100), wxSize(800, 700));
    // display the window
    frame->Show(TRUE);
    SetTopWindow(frame);
    return TRUE;
}

AdtFrame::AdtFrame (const wxString& title, const wxPoint& pos, const wxSize& size):wxFrame((wxFrame *) NULL, -1, title, pos, size){
    // set the frame icon
    SetIcon(wxIcon("myIcon.xpm"));
    // create a main menu bar
    wxMenuBar *menuBar = new wxMenuBar;
    // File menu
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Open, "&Open", "Open a file");
    menuFile->Append(ID_Save, "&Save", "Save your current work to file");
    menuFile->Append(ID_SaveAs, "S&ave As", "Save your current work as a new file");
    menuFile->Append(ID_Quit, "E&xit", "Exit the program");
    menuBar->Append(menuFile, "&File");
    // Display menu
    wxMenu *menuDisplay = new wxMenu;
    menuDisplay->Append(ID_DisplayFile, "D&isplay File", "Display the contents of the file");
    menuBar->Append(menuDisplay, "&Display");
    // Queue menu
    wxMenu *menuQueue = new wxMenu;
    menuQueue->Append(ID_CreateQueue, "&Create Queue", "Create a new Queue");
    menuQueue->Append(ID_AddData, "&Add Data", "Add a data item to the Queue");
    menuQueue->Append(ID_DisplayAllQ, "&Display All", "Show all the items in the Queue");
    menuQueue->Append(ID_ShowHeadQ, "Show &Head", "Show the item at the start of the Queue");
    menuQueue->Append(ID_ShowTailQ, "Show &Tail", "Show the item at the end of the Queue");
    menuQueue->Append(ID_Dequeue, "D&equeue", "Remove an item from the start of the Queue");
    menuBar->Append(menuQueue, "&Queue");
    // Deque menu
    wxMenu *menuDeque = new wxMenu;
    menuDeque->Append(ID_CreateDeque, "&Create Deque", "Create a new Dequeue");
    menuDeque->Append(ID_AddHead, "Add &Head", "Add an item to the start of the Deque");
    menuDeque->Append(ID_AddTail, "Add &Tail", "Add an item to the end of the Deque");
    menuDeque->Append(ID_DisplayAllD, "&Display All", "Show all items in the Deque");
    menuDeque->Append(ID_ShowHeadD, "Show H&ead", "Show the item at the start of the Deque");
    menuDeque->Append(ID_ShowTailD, "Show T&ail", "Show the item at the end of the Deque");
    menuDeque->Append(ID_DequeueHead, "De&queue Head", "Delete the item at the start of the Deque");
    menuDeque->Append(ID_DequeueTail, "Deq&ueue Tail", "Delete the item at the end of the Deque");
    menuBar->Append(menuDeque, "D&eque");
    // Priority Queue
    wxMenu *menuPriorityQueue = new wxMenu;
    menuPriorityQueue->Append(ID_CreatePQ, "&Create Priority Queue", "Create a new Priority Queue");
    menuPriorityQueue->Append(ID_AddDataPQ, "&Add Data", "Add an item to the Priority Queue");
    menuPriorityQueue->Append(ID_DisplayAllPQ, "&Display All", "Show all the items in the Priority Queue");
    menuPriorityQueue->Append(ID_ShowHeadPQ, "Show &Head", "Show the item at the start of the Priority Queue");
    menuPriorityQueue->Append(ID_ShowTailPQ, "Show &Tail", "Show the item at the end of the Priority Queue");
    menuPriorityQueue->Append(ID_DequeuePQ, "D&equeue", "Remove an item from the start of the Priority Queue");
    menuBar->Append(menuPriorityQueue, "Pr&iority Queue");
    // Stack menu
    wxMenu *menuStack = new wxMenu;
    menuStack->Append(ID_CreateStack, "&Create Stack", "Create a new Stack");
    menuStack->Append(ID_Pop, "&Pop", "Pop an item from the Stack");
    menuStack->Append(ID_Push, "P&ush", "Push an item onto the Stack");
    menuStack->Append(ID_DisplayAllS, "&Display All", "Show all items stored in the Stack");
    menuBar->Append(menuStack, "S&tack");
    //  BST menu
    wxMenu *menuBST = new wxMenu;
    menuBST->Append(ID_CreateBST, "&Create BST", "Create a new BST");
    menuBST->Append(ID_AddDataBST, "&Add Data", "Add a new data item to the BST");
    menuBST->Append(ID_DeleteDataBST, "&Delete Data", "Delete a data item from the BST");
    menuBST->Append(ID_InorderBST, "&Inorder", "Inorder traversal of the BST");
    menuBST->Append(ID_PreorderBST, "&Preorder", "Preorder traversal of the BST");
    menuBST->Append(ID_PostorderBST, "P&ostorder", "Postorder traversal of the BST");
    menuBar->Append(menuBST, "&BST");
    // AVL Tree menu
    wxMenu *menuAVLTree = new wxMenu;
    menuAVLTree->Append(ID_CreateAVL, "&Create AVL", "Create a new AVL Tree");
    menuAVLTree->Append(ID_AddDataAVL, "&Add Data", "Add a new data item to the AVL Tree");
    menuAVLTree->Append(ID_DeleteDataAVL, "&Delete Data", "Delete a data item from the AVL Tree");
    menuAVLTree->Append(ID_InorderAVL, "&Inorder", "Inorder traversal of the AVL Tree");
    menuAVLTree->Append(ID_PreorderAVL, "&Preorder", "Preorder traversal of the AVL Tree");
    menuAVLTree->Append(ID_PostorderAVL, "P&ostorder", "Postorder traversal of the AVL Tree");
    menuBar->Append(menuAVLTree, "&AVL Tree");
    // Heap menu
    wxMenu *menuHeap = new wxMenu;
    menuHeap->Append(ID_CreateHeap, "&Create Heap", "Create a new Heap");
    menuHeap->Append(ID_AddDataHeap, "&Add Data", "Add a new data item to the Heap");
    menuHeap->Append(ID_DeleteDataHeap, "&Delete Data", "Delete a data item from the Heap");
    menuHeap->Append(ID_DisplayAllHeap, "D&isplay All", "Show all items in the Heap");
    menuHeap->Append(ID_HeapSort, "&Heap Sort", "Sort the Heap");
    menuBar->Append(menuHeap, "&Heap");
    // RB Tree menu
    wxMenu *menuRedBlackTree = new wxMenu;
    menuRedBlackTree->Append(ID_CreateRB, "&Create RBT", "Create a new Red Black Tree");
    menuRedBlackTree->Append(ID_AddDataRB, "&Add Data", "Add a new data item to the Red Black Tree");
    menuRedBlackTree->Append(ID_DeleteDataRB, "&Delete Data", "Delete a data item from the Red Black Tree");
    menuRedBlackTree->Append(ID_InorderRB, "&Inorder", "Inorder traversal of the Red Black Tree");
    menuRedBlackTree->Append(ID_PreorderRB, "&Preorder", "Preorder traversal of the Red Black Tree");
    menuRedBlackTree->Append(ID_PostorderRB, "P&ostorder", "Postorder traversal of the Red Black Tree");
    menuBar->Append(menuRedBlackTree, "&RB Tree");
    // Splay menu
    wxMenu *menuSplayTree = new wxMenu;
    menuSplayTree->Append(ID_CreateSplay, "&Create Splay", "Create a new Splay Tree");
    menuSplayTree->Append(ID_AddDataSplay, "&Add Data", "Add a new data item to the Splay Tree");
    menuSplayTree->Append(ID_DeleteDataSplay, "&Delete Data", "Delete a data item from the Splay Tree");
    menuSplayTree->Append(ID_InorderSplay, "&Inorder", "Inorder traversal of the Splay Tree");
    menuSplayTree->Append(ID_PreorderSplay, "&Preorder", "Preorder traversal of the Splay Tree");
    menuSplayTree->Append(ID_PostorderSplay, "P&ostorder", "Postorder traversal of the Splay Tree");
    menuBar->Append(menuSplayTree, "Sp&lay Tree");
    // Set menu
    wxMenu *menuSets = new wxMenu;
    menuSets->Append(ID_CreateSets, "&Create Sets", "Create new sets");
    menuSets->Append(ID_AddDataSets, "Add &Data", "Add a data item to a set");
    menuSets->Append(ID_DisplaySetA, "Display Set&A", "Show the contents of Set A");
    menuSets->Append(ID_DisplaySetB, "Display Set&B", "Show the contents of Set B");
    menuSets->Append(ID_DisplayIn, "Display &Intersection", "Show the results of an intersection between the sets");
    menuSets->Append(ID_DisplayUn, "Display &Union", "Show the results of an intersection between the sets");
    menuSets->Append(ID_DeleteSetA, "D&elete from SetA", "Remove a data item from Set A");
    menuSets->Append(ID_DeleteSetB, "De&lete from SetB", "Remove a data item from Set B");
    menuBar->Append(menuSets, "&Set");
    // Help menu
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(ID_About, "&About", "About the application");
    menuHelp->Append(ID_Quit, "E&xit", "Exit the program");
    menuBar->Append(menuHelp, "Hel&p");
    // attach the menu bar to the frame
    SetMenuBar(menuBar);
    // create a status bar
    CreateStatusBar(3);
    SetStatusText("Ready...");
    SetStatusText("Dwayne Brathwaite", 1);
    SetStatusText("415001493", 2);

    wxPanel *panel = new wxPanel(this, -1);
    wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer *hbox1 = new wxBoxSizer(wxHORIZONTAL);

    wxBoxSizer *hbox2 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer *hbox3 = new wxBoxSizer(wxHORIZONTAL);

    wxStaticText *fileLabel = new wxStaticText(panel, wxID_ANY, "File Name");
    wxStaticText *displayLabel = new wxStaticText(panel, wxID_ANY, "Display");

    fileNameTextBox = new wxTextCtrl(panel, wxID_ANY, "No File Opened Yet...");
    mainEditBox = new wxTextCtrl(panel, wxID_ANY, "No Data Available Yet...", wxPoint(-1,-1), wxSize(-1,-1), wxTE_MULTILINE | wxTE_RICH);
    hbox1->Add(fileLabel, 0, wxRIGHT, 8);
    hbox1->Add(fileNameTextBox, 1);
    vbox->Add(hbox1, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);

    vbox->Add(-1, 10);
    hbox2->Add(displayLabel, 0);
    vbox->Add(hbox2, 0, wxLEFT | wxTOP, 10);
    vbox->Add(-1, 10);

    hbox3->Add(mainEditBox, 1, wxEXPAND);
    vbox->Add(hbox3, 1, wxLEFT | wxRIGHT | wxEXPAND, 10);

    vbox->Add(-1, 25);
    panel->SetSizer(vbox);

    Centre();
}

// convert a single record into a continuous string
string stringifyRecord(rec Record){
    string player;
    player = to_string(Record.rank);
    player.append("\t\t");
    player.append(Record.name);
    player.append("\t\t");
    player.append(Record.nationality);
    player.append("\t\t");
    player.append(to_string(Record.score));
    player.append("\t\t\t");
    player.append(Record.opponent);
    player.append("\t\t");
    player.append(to_string(Record.year));
    player.append("\n");
    return player;
}

// File menu functions
void AdtFrame::OnOpen(wxCommandEvent& event){
    // Create an open a file dialog
    SetStatusText("Opening file...");
    wxFileDialog *openDialog = new wxFileDialog(this, "Choose a file to open", wxEmptyString, wxEmptyString, "Data Files (*.dat)|*.dat|Text (*.txt)|*.txt|All files (*.*)|*.*", wxFD_OPEN, wxDefaultPosition);
    if (openDialog->ShowModal() == wxID_OK){
        currentFilePath = openDialog->GetPath();
        fileNameTextBox->Clear();
        fileNameTextBox->AppendText(currentFilePath);
        SetTitle(wxString("COMP2611 - Data Structures: 415001493"));
        string heading = "";
    string player = "";
    rec record;
    fstream datafile(currentFilePath.mb_str(), ios::in|ios::binary);
    if (datafile.is_open()){
        heading = "Rank\tName\t\tNationality\t\tScore\t\tOpponent\t\tYear\n";
        heading.append("===================================================================\n");
        mainEditBox->Clear();
        wxString headingLine(heading.c_str(), wxConvUTF8);
        mainEditBox->AppendText(headingLine);
        while (!datafile.eof()){
            datafile.read(reinterpret_cast<char*>(&record), sizeof(rec));
            player = stringifyRecord(record);
            wxString wxRecord(player.c_str(), wxConvUTF8);
            mainEditBox->AppendText(wxRecord);
            player = "";
        }
    }
    else {
        mainEditBox->AppendText("\n\n\t\tNo Data File Opened as Yet...\n\n");
        return;
    }
    }
    else
        mainEditBox->Clear();
    SetStatusText("Opened File");
}

void AdtFrame::OnSave(wxCommandEvent& event){
    // save a file
    mainEditBox->SaveFile(currentFilePath);
    SetStatusText("Saved File");
}

void AdtFrame::OnSaveAs(wxCommandEvent& event){
    // Create a save a file dialog to save a file with a new name
    SetStatusText("Saving...");
    wxFileDialog *saveDialog = new wxFileDialog(this, "Save File As...?", wxEmptyString, wxEmptyString, "Data Files (*.dat)|*.dat|Text files (*.txt)|*.txt", wxFD_SAVE | wxFD_OVERWRITE_PROMPT, wxDefaultPosition);
    if (saveDialog->ShowModal() == wxID_OK){
        currentFilePath = saveDialog->GetPath();
        mainEditBox->SaveFile(currentFilePath);
        SetTitle(wxString("COMP2611 - Data Structures: 415001493"));
    }
    SetStatusText("Saved File");
}

void AdtFrame::OnExit(wxCommandEvent& event){
    wxMessageBox("Thank you for using my app. Enjoy your day!", "Exit", wxOK | wxICON_INFORMATION, this);
    // close the window
    Close(TRUE);
}

// Display menu functions
void AdtFrame::OnDisplayFile(wxCommandEvent& event){
    // display the contents of the file
    string heading = "";
    string player = "";
    rec record;
    fstream datafile(currentFilePath.mb_str(), ios::in|ios::binary);
    if (datafile.is_open()){
        heading = "Rank\tName\t\tNationality\t\tScore\t\tOpponent\t\tYear\n";
        heading.append("===================================================================\n");
        mainEditBox->Clear();
        wxString headingLine(heading.c_str(), wxConvUTF8);
        mainEditBox->AppendText(headingLine);
        while (!datafile.eof()){
            datafile.read(reinterpret_cast<char*>(&record), sizeof(rec));
            player = stringifyRecord(record);
            wxString wxRecord(player.c_str(), wxConvUTF8);
            mainEditBox->AppendText(wxRecord);
            player = "";
        }
    }
    else {
        mainEditBox->AppendText("\n\n\t\tNo Data File Opened as Yet...\n\n");
        return;
    }
    SetStatusText("Showing File Contents");
}

// ======================= Queue menu functions ======================= 
void AdtFrame::OnCreateQueue(wxCommandEvent& event){
    // create a new Queue
    rec insertRec;

    dialogBox* inputDialog = new dialogBox("Inserting into the Queue", wxPoint(200,200), wxSize(310,375));
    if (inputDialog->ShowModal() == wxID_OK){

        insertRec.rank = inputDialog->rankSpinBox->GetValue();
        strncpy(insertRec.name, (const char*)inputDialog->nameTextBox->GetValue().mb_str(), 20);
        strncpy(insertRec.nationality, (const char*)inputDialog->nationalityComboBox->GetValue().mb_str(), 20);
        insertRec.score = inputDialog->scoreSpinBox->GetValue();
        strncpy(insertRec.opponent, (const char*)inputDialog->opponentComboBox->GetValue().mb_str(), 15);
        insertRec.year = inputDialog->yearSpinBox->GetValue();

        mainEditBox->Clear();
        mainEditBox->AppendText(stringifyRecord(insertRec));
        dataQ->enqueue(insertRec.rank, insertRec.name, insertRec.nationality, insertRec.score, insertRec.opponent, insertRec.year);
    }
    else {
        inputDialog->Close();
    }
    inputDialog->Destroy();
    SetStatusText("Inserted new record into the Queue");
}

void AdtFrame::OnAddData(wxCommandEvent& event){
    // add data to the Queue
    rec record;
    int count = 0;
    fstream datafile(currentFilePath.mb_str(), ios::in|ios::binary);
    if (datafile.is_open()){
        mainEditBox->Clear();
        while (!datafile.eof()){
            datafile.read(reinterpret_cast<char*>(&record), sizeof(rec));
            if (strstr(record.nationality, "New Zealand")){
                count++;
                dataQ->enqueue(record.rank, record.name, record.nationality, record.score, record.opponent, record.year);
            }
        }
        string msg = to_string(count);
        msg.append(" records were added to the Queue");
        wxString wxMsg(msg.c_str(), wxConvUTF8);
        mainEditBox->AppendText(wxMsg);
        SetStatusText("Added file records to Queue");
    }
    else {
        mainEditBox->AppendText("\n\n\t\tNo Data File Opened as Yet...\n\n");
        return;
    }
}

void AdtFrame::OnDisplayAllQ(wxCommandEvent& event){
    // Show all data stored in the Queue
    mainEditBox->Clear();
    string record = dataQ->showAll();
    if (record != "Queue is empty"){
        mainEditBox->AppendText("Showing all records in Queue\n\n");
        string heading = "Rank\tName\t\tNationality\t\tScore\t\tOpponent\t\tYear\n";
        heading.append("===================================================================\n");
        wxString headingLine(heading.c_str(), wxConvUTF8);
        mainEditBox->AppendText(headingLine);
        SetStatusText("Showing all records in Queue");
    }
    wxString wxRecord(record.c_str(), wxConvUTF8);
    mainEditBox->AppendText(wxRecord);
}

void AdtFrame::OnShowHeadQ(wxCommandEvent& event){
    // Show the item at the start of the Queue
    mainEditBox->Clear();
    string record = dataQ->showHead();
    if (record != "Queue is empty"){
        string heading = "Rank\tName\t\tNationality\t\tScore\t\tOpponent\t\tYear\n";
        heading.append("===================================================================\n");
        wxString headingLine(heading.c_str(), wxConvUTF8);
        mainEditBox->AppendText(headingLine);
        SetStatusText("Showing Head of Queue");
    }
    wxString wxRecord(record.c_str(), wxConvUTF8);
    mainEditBox->AppendText(wxRecord);
}

void AdtFrame::OnShowTailQ(wxCommandEvent& event){
    // Show the item at the end of the Queue
    mainEditBox->Clear();
    string record = dataQ->showTail();
    if (record != "Queue is empty"){
        string heading = "Rank\tName\t\tNationality\t\tScore\t\tOpponent\t\tYear\n";
        heading.append("===================================================================\n");
        wxString headingLine(heading.c_str(), wxConvUTF8);
        mainEditBox->AppendText(headingLine);
        SetStatusText("Showing Tail of Queue");
    }
    wxString wxRecord(record.c_str(), wxConvUTF8);
    mainEditBox->AppendText(wxRecord);
}

void AdtFrame::OnDequeue(wxCommandEvent& event){
    // Remove an item from the start of the Queue
    mainEditBox->Clear();
    string record = dataQ->dequeue();
    if (record != "Queue is empty"){
        mainEditBox->AppendText("Removing the following record from the Head of the Queue\n\n");
        string heading = "Rank\tName\t\tNationality\t\tScore\t\tOpponent\t\tYear\n";
        heading.append("===================================================================\n");
        wxString headingLine(heading.c_str(), wxConvUTF8);
        mainEditBox->AppendText(headingLine);
        SetStatusText("Item removed from Head of Queue");
    }
    wxString wxRecord(record.c_str(), wxConvUTF8);
    mainEditBox->AppendText(wxRecord);
}

// ======================= Deque menu functions ======================= 
void AdtFrame::OnCreateDeque(wxCommandEvent& event){
    // Create a new Deque
    rec insertRec;

    dialogBox* inputDialog = new dialogBox("Inserting at the front of the Deque", wxPoint(200,200), wxSize(310,375));
    if (inputDialog->ShowModal() == wxID_OK){

        insertRec.rank = inputDialog->rankSpinBox->GetValue();
        strncpy(insertRec.name, (const char*)inputDialog->nameTextBox->GetValue().mb_str(), 20);
        strncpy(insertRec.nationality, (const char*)inputDialog->nationalityComboBox->GetValue().mb_str(), 20);
        insertRec.score = inputDialog->scoreSpinBox->GetValue();
        strncpy(insertRec.opponent, (const char*)inputDialog->opponentComboBox->GetValue().mb_str(), 15);
        insertRec.year = inputDialog->yearSpinBox->GetValue();

        mainEditBox->Clear();
        mainEditBox->AppendText(stringifyRecord(insertRec));
        dataDQ->push_front(insertRec.rank, insertRec.name, insertRec.nationality, insertRec.score, insertRec.opponent, insertRec.year);
    }
    else {
        inputDialog->Close();
    }
    inputDialog->Destroy();
    SetStatusText("Inserted new record at the front of the Deque");
}

void AdtFrame::OnAddHead(wxCommandEvent& event){
    // Add item to start of the Deque
    rec record;
    int count = 0;
    fstream datafile(currentFilePath.mb_str(), ios::in|ios::binary);
    if (datafile.is_open()){
        mainEditBox->Clear();
        while (!datafile.eof()){
            datafile.read(reinterpret_cast<char*>(&record), sizeof(rec));
            if (strstr(record.nationality, "West Indies")){
                count++;
                dataDQ->push_front(record.rank, record.name, record.nationality, record.score, record.opponent, record.year);
            }
        }
        string msg = to_string(count);
        msg.append(" records were added to the Dequeue");
        wxString wxMsg(msg.c_str(), wxConvUTF8);
        mainEditBox->AppendText(wxMsg);
        SetStatusText("Added file records to Dequeue");
    }
    else {
        mainEditBox->AppendText("\n\n\t\tNo Data File Opened as Yet...\n\n");
        return;
    }
}

void AdtFrame::OnAddTail(wxCommandEvent& event){
    // Add item to the end of the Deque
    rec record;
    int count = 0;
    fstream datafile(currentFilePath.mb_str(), ios::in|ios::binary);
    if (datafile.is_open()){
        mainEditBox->Clear();
        while (!datafile.eof()){
            datafile.read(reinterpret_cast<char*>(&record), sizeof(rec));
            if (strstr(record.opponent, "West Indies")){
                count++;
                dataDQ->push_back(record.rank, record.name, record.nationality, record.score, record.opponent, record.year);
            }
        }
        string msg = to_string(count);
        msg.append(" records were added to the Dequeue");
        wxString wxMsg(msg.c_str(), wxConvUTF8);
        mainEditBox->AppendText(wxMsg);
        SetStatusText("Added file records to Dequeue");
    }
    else {
        mainEditBox->AppendText("\n\n\t\tNo Data File Opened as Yet...\n\n");
        return;
    }
}

void AdtFrame::OnDisplayAllD(wxCommandEvent& event){
    // Show all items in the Deque
    mainEditBox->Clear();
    string record = dataDQ->showAll();
    if (record != "Deque is empty"){
        mainEditBox->AppendText("Showing all records in Dequeue\n\n");
        string heading = "Rank\tName\t\tNationality\t\tScore\t\tOpponent\t\tYear\n";
        heading.append("===================================================================\n");
        wxString headingLine(heading.c_str(), wxConvUTF8);
        mainEditBox->AppendText(headingLine);
        SetStatusText("Showing all records in Dequeue");
    }
    wxString wxRecord(record.c_str(), wxConvUTF8);
    mainEditBox->AppendText(wxRecord);
}

void AdtFrame::OnShowHeadD(wxCommandEvent& event){
    // Show the item at the start of the Deque
    mainEditBox->Clear();
    string record = dataDQ->showHead();
    if (record != "Deque is empty"){
        string heading = "Rank\tName\t\tNationality\t\tScore\t\tOpponent\t\tYear\n";
        heading.append("===================================================================\n");
        wxString headingLine(heading.c_str(), wxConvUTF8);
        mainEditBox->AppendText(headingLine);
        SetStatusText("Showing Head of Dequeue");
    }
    wxString wxRecord(record.c_str(), wxConvUTF8);
    mainEditBox->AppendText(wxRecord);
}

void AdtFrame::OnShowTailD(wxCommandEvent& event){
    // Show the item at the end of the Deque
    mainEditBox->Clear();
    string record = dataDQ->showTail();
    if (record != "Deque is empty"){
        string heading = "Rank\tName\t\tNationality\t\tScore\t\tOpponent\t\tYear\n";
        heading.append("===================================================================\n");
        wxString headingLine(heading.c_str(), wxConvUTF8);
        mainEditBox->AppendText(headingLine);
        SetStatusText("Showing Tail of Dequeue");
    }
    wxString wxRecord(record.c_str(), wxConvUTF8);
    mainEditBox->AppendText(wxRecord);
}

void AdtFrame::OnDequeueHead(wxCommandEvent& event){
    // Delete the item at the start of the Deque
    mainEditBox->Clear();
    string record = dataDQ->pop_front();
    if (record != "Deque is empty"){
        mainEditBox->AppendText("Removing record from the Head of the Deque\n\n");
        string heading = "Rank\tName\t\tNationality\t\tScore\t\tOpponent\t\tYear\n";
        heading.append("===================================================================\n");
        wxString headingLine(heading.c_str(), wxConvUTF8);
        mainEditBox->AppendText(headingLine);
        SetStatusText("Item removed from Head of Deque");
    }
    wxString wxRecord(record.c_str(), wxConvUTF8);
    mainEditBox->AppendText(wxRecord);
}

void AdtFrame::OnDequeueTail(wxCommandEvent& event){
    // Delete the item at the end of the Deque
    mainEditBox->Clear();
    string record = dataDQ->pop_back();
    if (record != "Deque is empty"){
        mainEditBox->AppendText("Removing record from the Tail of the Deque\n\n");
        string heading = "Rank\tName\t\tNationality\t\tScore\t\tOpponent\t\tYear\n";
        heading.append("===================================================================\n");
        wxString headingLine(heading.c_str(), wxConvUTF8);
        mainEditBox->AppendText(headingLine);
        SetStatusText("Item removed from Tail of Deque");
    }
    wxString wxRecord(record.c_str(), wxConvUTF8);
    mainEditBox->AppendText(wxRecord);
}

// =======================  Priority Queue menu functions ======================= 
void AdtFrame::OnCreatePQ(wxCommandEvent& event){
    // create a new Priority Queue
    rec insertRec;

    dialogBox* inputDialog = new dialogBox("Inserting into the Priority Queue", wxPoint(200,200), wxSize(310,375));
    if (inputDialog->ShowModal() == wxID_OK){

        insertRec.rank = inputDialog->rankSpinBox->GetValue();
        strncpy(insertRec.name, (const char*)inputDialog->nameTextBox->GetValue().mb_str(), 20);
        strncpy(insertRec.nationality, (const char*)inputDialog->nationalityComboBox->GetValue().mb_str(), 20);
        insertRec.score = inputDialog->scoreSpinBox->GetValue();
        strncpy(insertRec.opponent, (const char*)inputDialog->opponentComboBox->GetValue().mb_str(), 15);
        insertRec.year = inputDialog->yearSpinBox->GetValue();

        mainEditBox->Clear();
        mainEditBox->AppendText(stringifyRecord(insertRec));
        dataPQ->enqueue(insertRec.rank, insertRec.name, insertRec.nationality, insertRec.score, insertRec.opponent, insertRec.year);
    }
    else {
        inputDialog->Close();
    }
    inputDialog->Destroy();
    SetStatusText("Inserted new record into the Priority Queue");

}

void AdtFrame::OnAddDataPQ(wxCommandEvent& event){
    // add data to the Priority Queue
    rec record;
    int count = 0;
    fstream datafile(currentFilePath.mb_str(), ios::in|ios::binary);
    if (datafile.is_open()){
        mainEditBox->Clear();
        while (!datafile.eof()){
            datafile.read(reinterpret_cast<char*>(&record), sizeof(rec));
            count++;
            dataPQ->enqueue(record.rank, record.name, record.nationality, record.score, record.opponent, record.year);
        }
        string msg = to_string(count);
        msg.append(" records were added to the Priority Queue");
        wxString wxMsg(msg.c_str(), wxConvUTF8);
        mainEditBox->AppendText(wxMsg);
        SetStatusText("Added file records to Priority Queue");
    }
    else {
        mainEditBox->AppendText("\n\n\t\tNo Data File Opened as Yet...\n\n");
        return;
    }
}

void AdtFrame::OnDisplayAllPQ(wxCommandEvent& event){
    // Show all data stored in the Priority Queue
    mainEditBox->Clear();
    string record = dataPQ->showAll();
    if (record != "Priority Queue is empty"){
        mainEditBox->AppendText("Showing all records in Priority Queue\n\n");
        string heading = "Rank\tName\t\tNationality\t\tScore\t\tOpponent\t\tYear\n";
        heading.append("===================================================================\n");
        wxString headingLine(heading.c_str(), wxConvUTF8);
        mainEditBox->AppendText(headingLine);
        SetStatusText("Showing all records in Priority Queue");
    }
    wxString wxRecord(record.c_str(), wxConvUTF8);
    mainEditBox->AppendText(wxRecord);
}

void AdtFrame::OnShowHeadPQ(wxCommandEvent& event){
    // Show the item at the start of the Priority Queue
    mainEditBox->Clear();
    string record = dataPQ->showHead();
    if (record != "Priority Queue is empty"){
        string heading = "Rank\tName\t\tNationality\t\tScore\t\tOpponent\t\tYear\n";
        heading.append("===================================================================\n");
        wxString headingLine(heading.c_str(), wxConvUTF8);
        mainEditBox->AppendText(headingLine);
        SetStatusText("Showing Head of Priority Queue");
    }
    wxString wxRecord(record.c_str(), wxConvUTF8);
    mainEditBox->AppendText(wxRecord);
}

void AdtFrame::OnShowTailPQ(wxCommandEvent& event){
    // Show the item at the end of the Priority Queue
    mainEditBox->Clear();
    string record = dataPQ->showTail();
    if (record != "Priority Queue is empty"){
        string heading = "Rank\tName\t\tNationality\t\tScore\t\tOpponent\t\tYear\n";
        heading.append("===================================================================\n");
        wxString headingLine(heading.c_str(), wxConvUTF8);
        mainEditBox->AppendText(headingLine);
        SetStatusText("Showing Tail of Priority Queue");
    }
    wxString wxRecord(record.c_str(), wxConvUTF8);
    mainEditBox->AppendText(wxRecord);
}

void AdtFrame::OnDequeuePQ(wxCommandEvent& event){
    // Remove an item from the start of the Priority Queue
    mainEditBox->Clear();
    string record = dataPQ->dequeue();
    if (record != "Priority Queue is empty"){
        mainEditBox->AppendText("Removing record from the Head of the Priority Queue\n\n");
        string heading = "Rank\tName\t\tNationality\t\tScore\t\tOpponent\t\tYear\n";
        heading.append("===================================================================\n");
        wxString headingLine(heading.c_str(), wxConvUTF8);
        mainEditBox->AppendText(headingLine);
        SetStatusText("Item removed from Head of Priority Queue");
    }
    wxString wxRecord(record.c_str(), wxConvUTF8);
    mainEditBox->AppendText(wxRecord);
}

// =======================  Stack menu ======================= 
void AdtFrame::OnCreateStack(wxCommandEvent& event){
    // Create a new Stack
    rec insertRec;

    dialogBox* inputDialog = new dialogBox("Inserting into the Stack", wxPoint(200,200), wxSize(310,375));
    if (inputDialog->ShowModal() == wxID_OK){

        insertRec.rank = inputDialog->rankSpinBox->GetValue();
        strncpy(insertRec.name, (const char*)inputDialog->nameTextBox->GetValue().mb_str(), 20);
        strncpy(insertRec.nationality, (const char*)inputDialog->nationalityComboBox->GetValue().mb_str(), 20);
        insertRec.score = inputDialog->scoreSpinBox->GetValue();
        strncpy(insertRec.opponent, (const char*)inputDialog->opponentComboBox->GetValue().mb_str(), 15);
        insertRec.year = inputDialog->yearSpinBox->GetValue();

        mainEditBox->Clear();
        mainEditBox->AppendText(stringifyRecord(insertRec));
        dataStack->push(insertRec.rank, insertRec.name, insertRec.nationality, insertRec.score, insertRec.opponent, insertRec.year);
    }
    else {
        inputDialog->Close();
    }
    inputDialog->Destroy();
    SetStatusText("Inserted new record into the Stack");
}

void AdtFrame::OnPop(wxCommandEvent& event){
    // Pop an item from the Stack
    mainEditBox->Clear();
    string record = dataStack->pop();
    if (record != "Stack is empty"){
        mainEditBox->AppendText("Removing record from the Top of the Stack\n\n");
        string heading = "Rank\tName\t\tNationality\t\tScore\t\tOpponent\t\tYear\n";
        heading.append("===================================================================\n");
        wxString headingLine(heading.c_str(), wxConvUTF8);
        mainEditBox->AppendText(headingLine);
        SetStatusText("Item removed from the top of the Stack");
    }
    wxString wxRecord(record.c_str(), wxConvUTF8);
    mainEditBox->AppendText(wxRecord);
}

void AdtFrame::OnPush(wxCommandEvent& event){
    // Push an item onto the Stack
    rec record;
    int count = 0;
    fstream datafile(currentFilePath.mb_str(), ios::in|ios::binary);
    if (datafile.is_open()){
        mainEditBox->Clear();
        while (!datafile.eof()){
            datafile.read(reinterpret_cast<char*>(&record), sizeof(rec));
            if (strstr(record.nationality, "Sri Lanka") || strstr(record.nationality, "Zimbabwe")){
                count++;
                dataStack->push(record.rank, record.name, record.nationality, record.score, record.opponent, record.year);
            }
        }
        string msg = to_string(count);
        msg.append(" records were added to the Stack");
        wxString wxMsg(msg.c_str(), wxConvUTF8);
        mainEditBox->AppendText(wxMsg);
        SetStatusText("Added file records to Stack");
    }
    else {
        mainEditBox->AppendText("\n\n\t\tNo Data File Opened as Yet...\n\n");
        return;
    }
}

void AdtFrame::OnDisplayAllS(wxCommandEvent& event){
    // Display all items stored in the Stack
    mainEditBox->Clear();
    string record = dataStack->showAll();
    if (record != "Stack is empty"){
        mainEditBox->AppendText("Showing all records in the Stack\n\n");
        string heading = "Rank\tName\t\tNationality\t\tScore\t\tOpponent\t\tYear\n";
        heading.append("===================================================================\n");
        wxString headingLine(heading.c_str(), wxConvUTF8);
        mainEditBox->AppendText(headingLine);
        SetStatusText("Showing all records in the Stack");
    }
    wxString wxRecord(record.c_str(), wxConvUTF8);
    mainEditBox->AppendText(wxRecord);
}

// =======================  BST menu ======================= 
void AdtFrame::OnCreateBST(wxCommandEvent& event){
    // Create a new BST
    rec insertRec;

    dialogBox* inputDialog = new dialogBox("Inserting into the BST", wxPoint(200,200), wxSize(310,375));
    if (inputDialog->ShowModal() == wxID_OK){

        insertRec.rank = inputDialog->rankSpinBox->GetValue();
        strncpy(insertRec.name, (const char*)inputDialog->nameTextBox->GetValue().mb_str(), 20);
        strncpy(insertRec.nationality, (const char*)inputDialog->nationalityComboBox->GetValue().mb_str(), 20);
        insertRec.score = inputDialog->scoreSpinBox->GetValue();
        strncpy(insertRec.opponent, (const char*)inputDialog->opponentComboBox->GetValue().mb_str(), 15);
        insertRec.year = inputDialog->yearSpinBox->GetValue();

        mainEditBox->Clear();
        mainEditBox->AppendText(stringifyRecord(insertRec));
        dataBST->insert(insertRec.rank, insertRec.name, insertRec.nationality, insertRec.score, insertRec.opponent, insertRec.year);
    }
    else {
        inputDialog->Close();
    }
    inputDialog->Destroy();
    SetStatusText("Inserted new record into the Binary Search Tree");
}

void AdtFrame::OnAddDataBST(wxCommandEvent& event){
    // Add an item to the BST
    rec record;
    int count = 0;
    fstream datafile(currentFilePath.mb_str(), ios::in|ios::binary);
    if (datafile.is_open()){
        mainEditBox->Clear();
        while (!datafile.eof()){
            datafile.read(reinterpret_cast<char*>(&record), sizeof(rec));
            count++;
            dataBST->insert(record.rank, record.name, record.nationality, record.score, record.opponent, record.year);
        }
        string msg = to_string(count);
        msg.append(" records were added to the Binary Search Tree");
        wxString wxMsg(msg.c_str(), wxConvUTF8);
        mainEditBox->AppendText(wxMsg);
        SetStatusText("Added file records to Binary Search Tree");
    }
    else {
        mainEditBox->AppendText("\n\n\t\tNo Data File Opened as Yet...\n\n");
        return;
    }
}

void AdtFrame::OnDeleteDataBST(wxCommandEvent& event){
    // Delete an item from the BST
    int theRank;
    mainEditBox->Clear();
    removeDialogBox* removeDialog = new removeDialogBox("Select rank to remove", wxPoint(200,200), wxSize(310,175));
    if (removeDialog->ShowModal() == wxID_OK){
        theRank = removeDialog->rankSpinBox->GetValue();
        dataBST->remove(theRank);
    }
    else {
    removeDialog->Close();
    }
    removeDialog->Destroy();
    wxString str ="Record with rank ";
    str.append(to_string(theRank));
    str.append(" removed.");
    mainEditBox->AppendText(str);
    SetStatusText("Item removed from BST");
}

void AdtFrame::OnInorderBST(wxCommandEvent& event){
    // Inorder traversal of the BST
    mainEditBox->Clear();
    string record = dataBST->inorder();
    if (record != ""){
        string heading = "Rank\tName\t\tNationality\t\tScore\t\tOpponent\t\tYear\n";
        heading.append("===================================================================\n");
        wxString headingLine(heading.c_str(), wxConvUTF8);
        mainEditBox->AppendText(headingLine);
        SetStatusText("BST Inorder");
    }
    else {
        record = "Binary Search Tree is empty";
    }
    wxString wxRecord(record.c_str(), wxConvUTF8);
    mainEditBox->AppendText(wxRecord);
}

void AdtFrame::OnPreorderBST(wxCommandEvent& event){
    // Preorder traversal of the BST
    mainEditBox->Clear();
    string record = dataBST->preorder();
    if (record != ""){
        string heading = "Rank\tName\t\tNationality\t\tScore\t\tOpponent\t\tYear\n";
        heading.append("===================================================================\n");
        wxString headingLine(heading.c_str(), wxConvUTF8);
        mainEditBox->AppendText(headingLine);
        SetStatusText("BST Preorder");
    }
    else {
        record = "Binary Search Tree is empty";
    }
    wxString wxRecord(record.c_str(), wxConvUTF8);
    mainEditBox->AppendText(wxRecord);
}

void AdtFrame::OnPostorderBST(wxCommandEvent& event){
    // Postorder traversal of the BST
    mainEditBox->Clear();
    string record = dataBST->postorder();
    if (record != ""){
        string heading = "Rank\tName\t\tNationality\t\tScore\t\tOpponent\t\tYear\n";
        heading.append("===================================================================\n");
        wxString headingLine(heading.c_str(), wxConvUTF8);
        mainEditBox->AppendText(headingLine);
        SetStatusText("BST Postorder");
    }
    else {
        record = "Binary Search Tree is empty";
    }
    wxString wxRecord(record.c_str(), wxConvUTF8);
    mainEditBox->AppendText(wxRecord);
}

// =======================  AVL menu ======================= 
void AdtFrame::OnCreateAVL(wxCommandEvent& event){
    // Create a new AVL
    rec insertRec;

    dialogBox* inputDialog = new dialogBox("Inserting into the AVL Tree", wxPoint(200,200), wxSize(310,375));
    if (inputDialog->ShowModal() == wxID_OK){

        insertRec.rank = inputDialog->rankSpinBox->GetValue();
        strncpy(insertRec.name, (const char*)inputDialog->nameTextBox->GetValue().mb_str(), 20);
        strncpy(insertRec.nationality, (const char*)inputDialog->nationalityComboBox->GetValue().mb_str(), 20);
        insertRec.score = inputDialog->scoreSpinBox->GetValue();
        strncpy(insertRec.opponent, (const char*)inputDialog->opponentComboBox->GetValue().mb_str(), 15);
        insertRec.year = inputDialog->yearSpinBox->GetValue();

        mainEditBox->Clear();
        mainEditBox->AppendText(stringifyRecord(insertRec));
        dataAVL->insert(insertRec.rank, insertRec.name, insertRec.nationality, insertRec.score, insertRec.opponent, insertRec.year);
    }
    else {
        inputDialog->Close();
    }
    inputDialog->Destroy();
    SetStatusText("Inserted new record into the AVL Tree");
}

void AdtFrame::OnAddDataAVL(wxCommandEvent& event){
    // Add an item to the AVL
    rec record;
    int count = 0;
    fstream datafile(currentFilePath.mb_str(), ios::in|ios::binary);
    if (datafile.is_open()){
        mainEditBox->Clear();
        while (!datafile.eof()){
            datafile.read(reinterpret_cast<char*>(&record), sizeof(rec));
            if (strstr(record.nationality, "Australia")){
                count++;
                dataAVL->insert(record.rank, record.name, record.nationality, record.score, record.opponent, record.year);
            }
        }
        string msg = to_string(count);
        msg.append(" records were added to the AVL Tree");
        wxString wxMsg(msg.c_str(), wxConvUTF8);
        mainEditBox->AppendText(wxMsg);
        SetStatusText("Added file records to AVL Tree");
    }
    else {
        mainEditBox->AppendText("\n\n\t\tNo Data File Opened as Yet...\n\n");
        return;
    }
}

void AdtFrame::OnDeleteDataAVL(wxCommandEvent& event){
    // Delete an item from the AVL
    int theRank;
    mainEditBox->Clear();
    removeDialogBox* removeDialog = new removeDialogBox("Select rank to remove", wxPoint(200,200), wxSize(310,175));
    if (removeDialog->ShowModal() == wxID_OK){
        theRank = removeDialog->rankSpinBox->GetValue();
        dataAVL->remove(theRank);
    }
    else {
    removeDialog->Close();
    }
    removeDialog->Destroy();
    wxString str ="Record with rank ";
    str.append(to_string(theRank));
    str.append(" removed.");
    mainEditBox->AppendText(str);
    SetStatusText("Item removed from AVL Tree");
}

void AdtFrame::OnInorderAVL(wxCommandEvent& event){
    // Inorder traversal of the AVL
    mainEditBox->Clear();
    string record = dataAVL->inorder();
    if (record != ""){
        string heading = "Rank\tName\t\tNationality\t\tScore\t\tOpponent\t\tYear\n";
        heading.append("===================================================================\n");
        wxString headingLine(heading.c_str(), wxConvUTF8);
        mainEditBox->AppendText(headingLine);
        SetStatusText("AVL Inorder");
    }
    else {
        record = "AVL Tree is empty";
    }
    wxString wxRecord(record.c_str(), wxConvUTF8);
    mainEditBox->AppendText(wxRecord);
}

void AdtFrame::OnPreorderAVL(wxCommandEvent& event){
    // Preorder traversal of the AVL
    mainEditBox->Clear();
    string record = dataAVL->preorder();
    if (record != ""){
        string heading = "Rank\tName\t\tNationality\t\tScore\t\tOpponent\t\tYear\n";
        heading.append("===================================================================\n");
        wxString headingLine(heading.c_str(), wxConvUTF8);
        mainEditBox->AppendText(headingLine);
        SetStatusText("AVL Preorder");
    }
    else {
        record = "AVL Tree is empty";
    }
    wxString wxRecord(record.c_str(), wxConvUTF8);
    mainEditBox->AppendText(wxRecord);
}

void AdtFrame::OnPostorderAVL(wxCommandEvent& event){
    // Postorder traversal of the AVL
    mainEditBox->Clear();
    string record = dataAVL->postorder();
    if (record != ""){
        string heading = "Rank\tName\t\tNationality\t\tScore\t\tOpponent\t\tYear\n";
        heading.append("===================================================================\n");
        wxString headingLine(heading.c_str(), wxConvUTF8);
        mainEditBox->AppendText(headingLine);
        SetStatusText("AVL Postorder");
    }
    else {
        record = "AVL Tree is empty";
    }
    wxString wxRecord(record.c_str(), wxConvUTF8);
    mainEditBox->AppendText(wxRecord);
}

// =======================  Heap menu ======================= 
void AdtFrame::OnCreateHeap(wxCommandEvent& event){
    // Create a new Heap
    rec insertRec;

    dialogBox* inputDialog = new dialogBox("Inserting into the MinHeap", wxPoint(200,200), wxSize(310,375));
    if (inputDialog->ShowModal() == wxID_OK){

        insertRec.rank = inputDialog->rankSpinBox->GetValue();
        strncpy(insertRec.name, (const char*)inputDialog->nameTextBox->GetValue().mb_str(), 20);
        strncpy(insertRec.nationality, (const char*)inputDialog->nationalityComboBox->GetValue().mb_str(), 20);
        insertRec.score = inputDialog->scoreSpinBox->GetValue();
        strncpy(insertRec.opponent, (const char*)inputDialog->opponentComboBox->GetValue().mb_str(), 15);
        insertRec.year = inputDialog->yearSpinBox->GetValue();

        mainEditBox->Clear();
        mainEditBox->AppendText(stringifyRecord(insertRec));
        dataMH->addMinHeap(insertRec.rank, insertRec.name, insertRec.nationality, insertRec.score, insertRec.opponent, insertRec.year);
    }
    else {
        inputDialog->Close();
    }
    inputDialog->Destroy();
    SetStatusText("Inserted new record into the MinHeap");
}

void AdtFrame::OnAddDataHeap(wxCommandEvent& event){
    // Add an item to the Heap
    rec record;
    int count = 0;
    fstream datafile(currentFilePath.mb_str(), ios::in|ios::binary);
    if (datafile.is_open()){
        mainEditBox->Clear();
        while (!datafile.eof()){
            datafile.read(reinterpret_cast<char*>(&record), sizeof(rec));
            if (strstr(record.nationality, "South Africa")){
                count++;
                dataMH->addMinHeap(record.rank, record.name, record.nationality, record.score, record.opponent, record.year);
            }
        }
        string msg = to_string(count);
        msg.append(" records were added to the Min Heap");
        wxString wxMsg(msg.c_str(), wxConvUTF8);
        mainEditBox->AppendText(wxMsg);
        SetStatusText("Added file records to Min Heap");
    }
    else {
        mainEditBox->AppendText("\n\n\t\tNo Data File Opened as Yet...\n\n");
        return;
    }
}

void AdtFrame::OnDeleteDataHeap(wxCommandEvent& event){
    // Delete an item from the Heap
    int theRank;
    mainEditBox->Clear();
    removeDialogBox* removeDialog = new removeDialogBox("Select rank to remove", wxPoint(200,200), wxSize(310,175));
    if (removeDialog->ShowModal() == wxID_OK){
        theRank = removeDialog->rankSpinBox->GetValue();
        dataMH->deleteMinHeapVal(theRank);
    }
    else {
    removeDialog->Close();
    }
    removeDialog->Destroy();
    wxString str ="Record with rank ";
    str.append(to_string(theRank));
    str.append(" removed.");
    mainEditBox->AppendText(str);
    SetStatusText("Item removed from MinHeap");
}

void AdtFrame::OnDisplayAllHeap(wxCommandEvent& event){
    // Show all items in the Heap
    mainEditBox->Clear();
    string record = dataMH->displayHeap();
    if (record != ""){
        mainEditBox->AppendText("Showing all records in the MinHeap\n\n");
        string heading = "Rank\tName\t\tNationality\t\tScore\t\tOpponent\t\tYear\n";
        heading.append("===================================================================\n");
        wxString headingLine(heading.c_str(), wxConvUTF8);
        mainEditBox->AppendText(headingLine);
        SetStatusText("Showing all records in the MinHeap");
    }
    else {
        record = "MinHeap is empty";
    }
    wxString wxRecord(record.c_str(), wxConvUTF8);
    mainEditBox->AppendText(wxRecord);
}

void AdtFrame::OnHeapSort(wxCommandEvent& event){
    // Sort the Heap
    mainEditBox->Clear();
    string record = dataMH->sortMinHeap();
    if (record != ""){
        mainEditBox->AppendText("Sorting records in the MinHeap\n\n");
        string heading = "Rank\tName\t\tNationality\t\tScore\t\tOpponent\t\tYear\n";
        heading.append("===================================================================\n");
        wxString headingLine(heading.c_str(), wxConvUTF8);
        mainEditBox->AppendText(headingLine);
        SetStatusText("Sorting records in the MinHeap");
    }
    else {
        record = "MinHeap is empty";
    }
    wxString wxRecord(record.c_str(), wxConvUTF8);
    mainEditBox->AppendText(wxRecord);
}

// =======================  RB menu ======================= 
void AdtFrame::OnCreateRB(wxCommandEvent& event){
    // Create a new RB
}

void AdtFrame::OnAddDataRB(wxCommandEvent& event){
    // Add an item to the RB
    // England players only********************************************************
}

void AdtFrame::OnDeleteDataRB(wxCommandEvent& event){
    // Delete an item from the RB
}

void AdtFrame::OnInorderRB(wxCommandEvent& event){
    // Inorder traversal of the RB
}

void AdtFrame::OnPreorderRB(wxCommandEvent& event){
    // Preorder traversal of the RB
}

void AdtFrame::OnPostorderRB(wxCommandEvent& event){
    // Postorder traversal of the RB
}

// =======================  Splay menu ======================= 
void AdtFrame::OnCreateSplay(wxCommandEvent& event){
    // Create a new Splay
}

void AdtFrame::OnAddDataSplay(wxCommandEvent& event){
    // Add an item to the Splay
    // India and Pakistan players only********************************************************
}

void AdtFrame::OnDeleteDataSplay(wxCommandEvent& event){
    // Delete an item from the Splay
}

void AdtFrame::OnInorderSplay(wxCommandEvent& event){
    // Inorder traversal of the Splay
}

void AdtFrame::OnPreorderSplay(wxCommandEvent& event){
    // Preorder traversal of the Splay
}

void AdtFrame::OnPostorderSplay(wxCommandEvent& event){
    // Postorder traversal of the Splay
}

// =======================  Set menu ======================= 
void AdtFrame::OnCreateSets(wxCommandEvent& event){
    // Create new sets
}

void AdtFrame::OnAddDataSets(wxCommandEvent& event){
    // Add a data item to a set
}

void AdtFrame::OnDisplaySetA(wxCommandEvent& event){
    // Show the contents of Set A
}

void AdtFrame::OnDisplaySetB(wxCommandEvent& event){
    // Show the contents of Set B
}

void AdtFrame::OnDisplayIn(wxCommandEvent& event){
    // Show the results of an intersection between the sets
}

void AdtFrame::OnDisplayUn(wxCommandEvent& event){
    // Show the results of a union between the sets
}

void AdtFrame::OnDeleteSetA(wxCommandEvent& event){
    // Remove a data item from Set A
}

void AdtFrame::OnDeleteSetB(wxCommandEvent& event){
    // Remove a data item from Set B
}


// =======================  Help menu ======================= 
void AdtFrame::OnAbout(wxCommandEvent& event){
    // Show information about the application
    wxMessageBox("Developed by Dwayne Brathwaite\nWritten in C++ & wxWidgets 3\ncompiled on a x64 Linux PC", "&Ok", wxOK | wxICON_INFORMATION, this);
}