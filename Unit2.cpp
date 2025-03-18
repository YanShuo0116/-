//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <stack>
#include <queue>
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

// 定義節點的結構
struct BSTreeNode {
    struct BSTreeNode *leftchild;
    int data;
    struct BSTreeNode *rightchild;
};

struct BSTreeNode *root = NULL; // 合併為唯一的 root 變數

struct FixBSTreeNode {
    struct FixBSTreeNode *leftchild;
    struct FixBSTreeNode *rightchild;
    char data_c;
};

struct FixBSTreeNode *newFixNode(char data_c) {
    struct FixBSTreeNode *node = new struct FixBSTreeNode;
    node->data_c = data_c;
    node->leftchild = NULL;
    node->rightchild = NULL;
    return node;
}

// 找樹中最小值的輔助
struct BSTreeNode *findMin(struct BSTreeNode *node);

// 存儲樹的狀態
String tree = "";

// 建立新的節點
struct BSTreeNode * newNode(int x) {
	struct BSTreeNode * node = new struct BSTreeNode;
	node->data = x;
	node->leftchild = NULL;
	node->rightchild = NULL;
	return node;
}

// 插入新節點到樹中
struct BSTreeNode * insertBSTree(struct BSTreeNode * node, int x){
	if (node == NULL) return newNode(x);
	if (x < node->data)
		node->leftchild = insertBSTree(node->leftchild, x);
	else
		node->rightchild = insertBSTree(node->rightchild, x);
	return node;
}

// 刪除樹中指定數值的節點
struct BSTreeNode *deleteBSTNode(struct BSTreeNode *node, int target)
{
    if (node == NULL)
		return node;

	if (target < node->data)
		node->leftchild = deleteBSTNode(node->leftchild, target);
	else if (target > node->data)
        node->rightchild = deleteBSTNode(node->rightchild, target);
	else
	{

		if (node->leftchild == NULL && node->rightchild == NULL)
		{

			delete node;
			return NULL;
        }
		else if (node->leftchild == NULL)
        {

			struct BSTreeNode *temp = node->rightchild;
			delete node;
			return temp;
		}
        else if (node->rightchild == NULL)
        {

			struct BSTreeNode *temp = node->leftchild;
            delete node;
			return temp;
		}
		else
		{

            struct BSTreeNode *temp = findMin(node->rightchild);
			node->data = temp->data;
			node->rightchild = deleteBSTNode(node->rightchild, temp->data);
		}
	}
	return node;
}

// 尋找樹中最小值的輔助
struct BSTreeNode *findMin(struct BSTreeNode *node)
{
	while (node->leftchild != NULL)
		node = node->leftchild;
	return node;
}
// 搜尋否存在指定值
bool searchBST(struct BSTreeNode *node, int target)
{
	if (node == NULL)
		return false;

	if (target == node->data)
		return true;
	else if (target < node->data)
		return searchBST(node->leftchild, target);
	else
		return searchBST(node->rightchild, target);
}

//迴圈版

 void InsertNode(struct BSTreeNode *&root, int data, bool isRecursive) {
	if (isRecursive)
		root = insertBSTree(root, data);
	else {

		struct BSTreeNode *newNode = new struct BSTreeNode;
		newNode->data = data;
		newNode->leftchild = NULL;
		newNode->rightchild = NULL;

		if (root == NULL) {
			root = newNode;
			return;
		}

		struct BSTreeNode *current = root;
		struct BSTreeNode *parent = NULL;
		while (true) {
			parent = current;
			if (data < current->data) {
				current = current->leftchild;
                if (current == NULL) {
					parent->leftchild = newNode;
                    return;
				}
			} else {
                current = current->rightchild;
                if (current == NULL) {
					parent->rightchild = newNode;
                    return;
                }
            }
		}
	}
}

bool SearchNode(struct BSTreeNode *root, int target, bool isRecursive) {
	if (isRecursive)
	   return  searchBST(root, target);
	else {

		struct BSTreeNode *current = root;
		while (current != NULL) {
			if (target == current->data)
				return true;
			else if (target < current->data)
				current = current->leftchild;
			else
				current = current->rightchild;
		}
		return false;
	}
}


void DeleteNode(struct BSTreeNode *&root, int target, bool isRecursive) {
	if (isRecursive)
		root = deleteBSTNode(root, target);
	else {

		struct BSTreeNode *current = root;
		struct BSTreeNode *parent = NULL;
		while (current != NULL && current->data != target) {
			parent = current;
			if (target < current->data)
				current = current->leftchild;
			else
                current = current->rightchild;
        }
        if (current == NULL)
			return;
        if (current->leftchild == NULL && current->rightchild == NULL) {
			if (current == root)
				root = NULL;
			else if (parent->leftchild == current)
                parent->leftchild = NULL;
			else
                parent->rightchild = NULL;
            delete current;
        } else if (current->leftchild == NULL) {
            if (current == root)
                root = current->rightchild;
			else if (parent->leftchild == current)
                parent->leftchild = current->rightchild;
			else
				parent->rightchild = current->rightchild;
            delete current;
        } else if (current->rightchild == NULL) {
            if (current == root)
                root = current->leftchild;
            else if (parent->leftchild == current)
				parent->leftchild = current->leftchild;
			else
                parent->rightchild = current->leftchild;
			delete current;
        } else {
            struct BSTreeNode *successor = findMin(current->rightchild);
            current->data = successor->data;
            DeleteNode(current->rightchild, successor->data, false);
        }
	}
}



// 中序
String printBSTree(struct BSTreeNode * node) {
	String tree;
	if (node != NULL) {
		tree += printBSTree(node->leftchild);
		tree += IntToStr(node->data) + "→";
		tree += printBSTree(node->rightchild);
	}
	return tree;
}



// 前序
void preorderTraversal(struct BSTreeNode * node){
	if (node != NULL) {
		tree += IntToStr(node->data) + "→";
		preorderTraversal(node->leftchild);
		preorderTraversal(node->rightchild);
	}
}

// 後序
void postorderTraversal(struct BSTreeNode * node){
	if (node != NULL) {
		postorderTraversal(node->leftchild);
		postorderTraversal(node->rightchild);
		tree += IntToStr(node->data) + "→";
	}
}

// 迴圈版本的中序走訪
String loopInorderTraversal(struct BSTreeNode *node) {
	String tree;
	std::stack<BSTreeNode*> stack;
	BSTreeNode* current = node;
	while (current != NULL || !stack.empty()) {
		while (current != NULL) {
			stack.push(current);
			current = current->leftchild;
		}
		current = stack.top();
		stack.pop();
		tree += IntToStr(current->data) + "→";
		current = current->rightchild;
	}
	return tree;
}

// 迴圈版本的前序走訪
String loopPreorderTraversal(struct BSTreeNode *node) {
	String tree;
	if (node == NULL)
		return tree;
	std::stack<BSTreeNode*> stack;
	stack.push(node);
	while (!stack.empty()) {
		BSTreeNode* current = stack.top();
		stack.pop();
		tree += IntToStr(current->data) + "→";
		if (current->rightchild != NULL)
			stack.push(current->rightchild);
		if (current->leftchild != NULL)
			stack.push(current->leftchild);
	}
	return tree;
}

// 迴圈版本的後序走訪
String loopPostorderTraversal(struct BSTreeNode *node) {
	String tree;
	if (node == NULL)
		return tree;
	std::stack<BSTreeNode*> stack;
	stack.push(node);
	BSTreeNode* prev = NULL;
	while (!stack.empty()) {
		BSTreeNode* current = stack.top();
		if ((current->leftchild == NULL && current->rightchild == NULL) ||
			(prev != NULL && (prev == current->leftchild || prev == current->rightchild))) {
			tree += IntToStr(current->data) + "→";
			stack.pop();
			prev = current;
		} else {
			if (current->rightchild != NULL)
				stack.push(current->rightchild);
			if (current->leftchild != NULL)
				stack.push(current->leftchild);
		}
	}
	return tree;
}

// 階層走訪
String levelOrderTraversal(struct BSTreeNode *root) {
    String tree;
	if (root == NULL)
		return tree;

	std::queue<BSTreeNode*> q;
	q.push(root);

	while (!q.empty()) {
		BSTreeNode* current = q.front();
		q.pop();
		tree += IntToStr(current->data) + "→";

		if (current->leftchild != NULL)
			q.push(current->leftchild);
		if (current->rightchild != NULL)
			q.push(current->rightchild);
	}
	return tree;
}
 void clearBStree(struct BSTreeNode *& node) {
	if (node == NULL)
		return;

	// 後序，刪除每個節點
	clearBStree(node->leftchild);
	clearBStree(node->rightchild);

	delete node;
	node = NULL;
}


//////////////////////////////////////////////////////////////////////////////////////////////test

// 建立樹
struct FixBSTreeNode *BuildBTree_InfixPrefix(AnsiString prefix, AnsiString infix) {
	struct FixBSTreeNode *node;

	if (infix.Length() == 0)
		return NULL;

	int k = AnsiPos(prefix[1], infix);

	node = newFixNode(prefix[1]); // 使用 newFixNode 函數建立新節點

	node->leftchild = BuildBTree_InfixPrefix(prefix.SubString(2, k - 1), infix.SubString(1, k - 1));
	node->rightchild = BuildBTree_InfixPrefix(prefix.SubString(k + 1, prefix.Length() - k), infix.SubString(k + 1, infix.Length() - k));

	return node;
}
FixBSTreeNode* BuildBTree_InfixPostfix(AnsiString postfix, AnsiString inorder) {
    if (postfix.IsEmpty() || inorder.IsEmpty() || postfix.Length() != inorder.Length())
        return NULL;

    FixBSTreeNode* root = new FixBSTreeNode;
    root->data_c = postfix[postfix.Length()];
    root->leftchild = root->rightchild = NULL;

    int rootIndex = inorder.Pos(root->data_c);

    AnsiString leftInorder = inorder.SubString(1, rootIndex - 1);
    AnsiString rightInorder = inorder.SubString(rootIndex + 1, inorder.Length() - rootIndex);

    AnsiString leftPostfix = postfix.SubString(1, leftInorder.Length());
    AnsiString rightPostfix = postfix.SubString(leftInorder.Length() + 1, rightInorder.Length());

    root->leftchild = BuildBTree_InfixPostfix(leftPostfix, leftInorder);
    root->rightchild = BuildBTree_InfixPostfix(rightPostfix, rightInorder);

    return root;
}

// 輸出子樹
void printSubtree(FixBSTreeNode* root, AnsiString prefix, AnsiString indent, TMemo* memo) {
	if (root == NULL)
		return;

	AnsiString nodeComparison = indent + prefix + " vs. " + root->data_c;
	memo->Lines->Add(nodeComparison);

	AnsiString childPrefix = prefix + root->data_c;
	AnsiString childIndent = indent + "    ";

	if (root->leftchild) {
		AnsiString leftSubtreeHeader = childIndent + "left subtree=";
		memo->Lines->Add(leftSubtreeHeader);
		printSubtree(root->leftchild, childPrefix, childIndent, memo);
	}

	if (root->rightchild) {
		AnsiString rightSubtreeHeader = childIndent + "right subtree=";
        memo->Lines->Add(rightSubtreeHeader);
        printSubtree(root->rightchild, childPrefix, childIndent, memo);
	}
}







// 清空二叉樹
void clearBSTree(FixBSTreeNode *& node) {
	if (node == NULL)
		return;

	// 後序，刪除每個節點
	clearBSTree(node->leftchild);
	clearBSTree(node->rightchild);

	delete node;
	node = NULL;
}



TForm2 *Form2;

__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
	// 初始化 TrackBar1 和 TrackBar2 的位置
	TrackBar1->Position = 250;
	TrackBar2->Position = 50;
	// 初始化 bitmap
	maxLevel = 5;
	bitmap = new Graphics::TBitmap();
	bitmap->Width = PaintBox1->Width;
	bitmap->Height = PaintBox1->Height;
	RadioButton1->Checked = true;

}

// 將數值插入樹中
void __fastcall TForm2::Button1Click(TObject *Sender)
{
	int data = Edit1->Text.ToInt();
	bool isRecursive = RadioButton1->Checked;
	InsertNode(root, data, isRecursive);
	String tree = printBSTree(root);
	Memo1->Lines->Add(tree);
	PaintBox1->Invalidate(); // 更新 PaintBox
}

// 搜尋是否存在指定值
void __fastcall TForm2::Button2Click(TObject *Sender)
{
	int target = Edit1->Text.ToInt();
	bool isRecursive = RadioButton1->Checked;
	if (SearchNode(root, target, isRecursive))
		Memo1->Lines->Add("找到 " + IntToStr(target) + "!!!");
	else
		Memo1->Lines->Add("目標不存在於樹中！");
}

// 刪除樹中指定值節點
void __fastcall TForm2::Button3Click(TObject *Sender)
{
	int target = Edit1->Text.ToInt();
	bool isRecursive = RadioButton1->Checked;
	if (SearchNode(root, target, isRecursive)) {
		DeleteNode(root, target, isRecursive);
        String tree = printBSTree(root);
		Memo1->Lines->Add("刪除 " + IntToStr(target) + " 成功！");
        Memo1->Lines->Add("更新後樹的狀態：" + tree);
	} else
		Memo1->Lines->Add("目標不存在於樹中，刪除失敗！");
	PaintBox1->Invalidate();

}

void __fastcall TForm2::DrawTree(struct BSTreeNode *node, int x, int y, int level, int radius, int spacing, int maxNodes)
{
	static int nodeCount = 0; // 紀錄已繪製的節點數量

	if (node == NULL || nodeCount >= maxNodes)
		return;

	// 繪製節點
	bitmap->Canvas->Ellipse(x - radius, y - radius, x + radius, y + radius);
	bitmap->Canvas->TextOut(x - 5, y - 5, IntToStr(node->data));
	nodeCount++; // 每繪製一個節點，增加節點數量

	// 繪製連線和子節點
	if (node->leftchild != NULL && nodeCount < maxNodes)
	{
		int x_left = x - spacing * (1 << (maxLevel - level - 1));
		int y_left = y + 50;
		bitmap->Canvas->MoveTo(x, y + radius);
		bitmap->Canvas->LineTo(x_left, y_left - radius);
		DrawTree(node->leftchild, x_left, y_left, level + 1, radius, spacing, maxNodes);
	}
	if (node->rightchild != NULL && nodeCount < maxNodes)
	{
		int x_right = x + spacing * (1 << (maxLevel - level - 1));
		int y_right = y + 50;
		bitmap->Canvas->MoveTo(x, y + radius);
		bitmap->Canvas->LineTo(x_right, y_right - radius);
		DrawTree(node->rightchild, x_right, y_right, level + 1, radius, spacing, maxNodes);
	}
}

// 中序結果
void __fastcall TForm2::Button5Click(TObject *Sender)
{
	tree="";
	if (RadioButton1->Checked)
		tree = loopInorderTraversal(root);
	else
		tree = printBSTree(root);
	Memo1->Lines->Add("中序走訪結果：" + tree);
}

// 前序結果
void __fastcall TForm2::Button4Click(TObject *Sender)
{
	tree="";
	if (RadioButton1->Checked)
		tree = loopPreorderTraversal(root);
	else
		preorderTraversal(root);
	Memo1->Lines->Add("前序走訪結果：" + tree);
}

// 後序結果
void __fastcall TForm2::Button6Click(TObject *Sender)
{
	tree="";
	if (RadioButton1->Checked)
		tree = loopPostorderTraversal(root);
	else
		postorderTraversal(root);
	Memo1->Lines->Add("後序走訪結果：" + tree);
}


// 更新 Label2 的顯示
void __fastcall TForm2::TrackBar1Change(TObject *Sender)
{
	Label2->Caption = IntToStr(TrackBar1->Position);
}

//更新 Label3 的顯示
void __fastcall TForm2::TrackBar2Change(TObject *Sender)
{
	Label3->Caption = IntToStr(TrackBar2->Position);
}

// 將隨機數加入樹中
void __fastcall TForm2::Button7Click(TObject *Sender)
{
	int range = TrackBar1->Position;
	int numRandoms = TrackBar2->Position;

	for (int i = 0; i < numRandoms; ++i)
	{
		int randomValue = rand() % range + 1;
		root = insertBSTree(root, randomValue);
	}

	String tree = printBSTree(root);
	Memo1->Lines->Add("將 " + IntToStr(numRandoms) + " 個隨機數加入樹中(Range 1 to " + IntToStr(range) + ")");
	Memo1->Lines->Add(tree);
	PaintBox1->Invalidate(); // 更新 PaintBox
}

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

void __fastcall TForm2::PaintBox1Paint(TObject *Sender)
{
	// 清空 bitmap
	bitmap->Canvas->Brush->Color = clWhite;
	bitmap->Canvas->FillRect(Rect(0, 0, PaintBox1->Width, PaintBox1->Height));

	// 設定節點的半徑和間距
	int radius =12; // 節點的半徑
	int spacing = 10; // 節點之間的間距

	DrawTree(root, PaintBox1->Width / 2, 50, 0, radius, spacing, 1000);

	// 將 bitmap 繪製到 PaintBox 上
	PaintBox1->Canvas->Draw(0, 0, bitmap);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button8Click(TObject *Sender)
{
	clearBStree(root);
	// 清空 Memo1
	Memo1->Lines->Clear();
	// 重繪 PaintBox1
	PaintBox1->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button9Click(TObject *Sender)
{
	String tree = levelOrderTraversal(root);
	Memo1->Lines->Add("階層走訪結果：" + tree);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button10Click(TObject *Sender)
{
    Memo2->Lines->Clear();

    AnsiString inorder = Edit2->Text;
    AnsiString preorder = Edit3->Text;

    FixBSTreeNode* treeFromInPre = BuildBTree_InfixPrefix(preorder, inorder);

	Memo2->Lines->Add("infix: " + inorder);
    Memo2->Lines->Add("prefix: " + preorder);
    Memo2->Lines->Add("Comparing process:");

    printSubtree(treeFromInPre, "", "", Memo2);

	clearBSTree(treeFromInPre);
}


//---------------------------------------------------------------------------


void __fastcall TForm2::Button11Click(TObject *Sender)
{
  Memo2->Lines->Clear();

    AnsiString inorder = Edit2->Text;
    AnsiString postfix = Edit4->Text;

    FixBSTreeNode* treeFromInPost = BuildBTree_InfixPostfix(postfix, inorder);

    Memo2->Lines->Add("infix: " + inorder);
    Memo2->Lines->Add("postfix: " + postfix);
    Memo2->Lines->Add("Comparing process:");

    printSubtree(treeFromInPost, "", "", Memo2);

    clearBSTree(treeFromInPost);
}
//---------------------------------------------------------------------------

