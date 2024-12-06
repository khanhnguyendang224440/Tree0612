#include <iostream>
using namespace std;

// Cau truc Node
struct Node {
    char duLieu;       // Gia tri cua node (toan tu hoac toan hang)
    Node* trai;        // Con trai
    Node* phai;        // Con phai

    // Ham tao Node moi
    Node(char val) {
        duLieu = val;
        trai = nullptr;
        phai = nullptr;
    }
};

// Ham tao cay bieu thuc tu bieu thuc hau to
Node* taoCayBieuThuc(char bieuThuc[], int doDai) {
    Node* nganXep[100]; // Ngan xep de luu cac node
    int dinh = -1;      // Con tro dinh cua ngan xep

    // Duyet qua tung ky tu trong bieu thuc hau to
    for (int i = 0; i < doDai; i++) {
        char c = bieuThuc[i];

        // Neu la toan hang: tao node moi va day vao ngan xep
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            nganXep[++dinh] = new Node(c);
        }
        // Neu la toan tu: tao node cha
        else {
            Node* nutMoi = new Node(c);
            nutMoi->phai = nganXep[dinh--]; // Lay con phai tu ngan xep
            nutMoi->trai = nganXep[dinh--]; // Lay con trai tu ngan xep
            nganXep[++dinh] = nutMoi;       // Day node cha vao ngan xep
        }
    }

    // Phan tu cuoi cung trong ngan xep la goc cua cay
    return nganXep[dinh];
}

// Ham duyet cay theo thu tu truoc (Pre-order)
void duyetTruoc(Node* goc) {
    if (goc == nullptr) return;

    cout << goc->duLieu << " ";   // In gia tri cua node
    duyetTruoc(goc->trai);        // Duyet cay con trai
    duyetTruoc(goc->phai);        // Duyet cay con phai
}

// Ham duyet cay theo thu tu giua (In-order)
void duyetGiua(Node* goc) {
    if (goc == nullptr) return;

    duyetGiua(goc->trai);         // Duyet cay con trai
    cout << goc->duLieu << " ";  // In gia tri cua node
    duyetGiua(goc->phai);         // Duyet cay con phai
}

// Ham duyet cay theo thu tu sau (Post-order)
void duyetSau(Node* goc) {
    if (goc == nullptr) return;

    duyetSau(goc->trai);          // Duyet cay con trai
    duyetSau(goc->phai);          // Duyet cay con phai
    cout << goc->duLieu << " ";  // In gia tri cua node
}

int main() {
    // Bieu thuc hau to dau vao
    char bieuThuc[] = {'a', '5', 'b', '*', 'c', '/', '+', 'c', '8', '^', '-', 'd', 'e', '1', '2', '/', '^', '*', '+'};
    int doDai = sizeof(bieuThuc) / sizeof(bieuThuc[0]);

    // Tao cay bieu thuc
    Node* goc = taoCayBieuThuc(bieuThuc, doDai);

    // In ket qua duyet cay theo cac cach
    cout << "Duyet truoc (Pre-order): ";
    duyetTruoc(goc);
    cout << endl;

    cout << "Duyet giua (In-order): ";
    duyetGiua(goc);
    cout << endl;

    cout << "Duyet sau (Post-order): ";
    duyetSau(goc);
    cout << endl;

    return 0;
}

