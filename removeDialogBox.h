#ifndef REMOVEDIALOGBOX_H
#define REMOVEDIALOGBOX_H

class removeDialogBox: public wxDialog{
    public:
        removeDialogBox(const wxString& title, const wxPoint& pos, const wxSize& size);
        wxSpinCtrl* rankSpinBox;
};

removeDialogBox::removeDialogBox (const wxString& title, const wxPoint& pos, const wxSize& size): wxDialog((wxDialog *)NULL, -1, title, pos, size){
    wxPanel *panel = new wxPanel(this, -1);
    wxStaticText *rankLabel = new wxStaticText(panel, wxID_ANY, "Rank", wxPoint(25, 30));
    rankSpinBox = new wxSpinCtrl(panel, -1, "0", wxPoint(65, 25), wxSize(70, -1), wxSP_ARROW_KEYS, 1, 200, 1);
    wxButton* okBtn = new wxButton(panel, wxID_OK, "&DELETE", wxPoint(75, 100), wxDefaultSize, 0);
    wxButton* cancelBtn = new wxButton(panel, wxID_CANCEL, "&CANCEL", wxPoint(170, 100), wxDefaultSize, 0 );
    Centre();
}
#endif