/***************************************************************************************

* File Name : LinkList.h
* CopyRight : 2024 QG Studio
* SYSTEM : win11
* Create Data : 2024.03.16
  *
  *
  *--------------------------------Revision History--------------------------------------
* No	version		Data			Revised By			Item			Description
  *
  *
  ***************************************************************************************/

  /**************************************************************

  *	Multi-Include-Prevent Section
	**************************************************************/

#ifndef Linkedlist_H_INCLUDED
#define Linkedlist_H_INCLUDED
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//???疑惑，用assert结果每个函数都出错

	/**************************************************************

	*	Macro Define Section
	  **************************************************************/

#define OK 1
#define ERROR 0


	  /**************************************************************

	  *	Struct Define Section
		**************************************************************/

		// define element type
typedef int ElemType;
typedef char Status;

// define struct of linked list
typedef struct ListNode {
	ElemType data;
	struct ListNode * next;
} ListNode, * ListN;

typedef struct two_ways_ListNode {
	ElemType data;
	struct two_ways_ListNode* prior, * next;
}two_ListNode,*twoL;


/**************************************************************

*	Prototype Declare Section
  **************************************************************/

  /**

   *  @name        : void menus()
   *  @description : the menus of operation
   *  @param		 : None
   *  @return		 : void
   *  @notice      : None
     */
void menus();

/**

 *  @name        : void print(Status c)
 *  @description : the result of operation
 *  @param		 : c(Status)
 *  @return		 : void
 *  @notice      : None
   */
void print(Status c);

/**

 *  @name        : ListN InitList()
 *  @description : initialize an empty linked list with only the head node
 *  @param		 : None
 *  @return		 : ListN
 *  @notice      : None
	*/
ListN InitList();

/**

 *  @name        : Status CreateList1(ListN L,int n)
 *  @description : create a linked list with n nodes from head to rear
 *  @param		 : L(the head node),n(the quantity of nodes)
 *  @return		 : status
 *  @notice      : None
	*/
Status CreateList1(ListN L, int n);

/**

 *  @name        : Status CreateList2(ListN L,int n)
 *  @description : create a linked list with n nodes from rear to head
 *  @param		 : L(the head node),n(the quantity of nodes)
 *  @return		 : status
 *  @notice      : None
	*/
Status CreateList2(ListN L, int n);

/**

 *  @name        : Status DestroyList(ListN* L)
 *  @description : destroy each node of linked list,include the head node
 *  @param		 : L(the head node)
 *  @return		 : Status
 *  @notice      : None
	*/
Status DestroyList(ListN* L);

/**

 *  @name        : Status ClearList(ListN L)
 *  @description : clear each node's data of linked list
 *  @param		 : L(the head node)
 *  @return		 : Status
 *  @notice      : None
	*/
Status ClearList(ListN L);

/**

 *  @name        : bool List_IsEmpty(ListN L)
 *  @description : check whether the linked list is empty
 *  @param		 : L(the head node)
 *  @return		 : bool
 *  @notice      : None
	*/
bool List_IsEmpty(ListN L);

/**

 *  @name        : int ListLength(ListN L)
 *  @description : count the length of the linked list
 *  @param		 : L(the head node)
 *  @return		 : int 
 *  @notice      : None
	*/
int ListLength(ListN L);

/**

 *  @name        : Status GetElem(ListN L,int i,ElemType * e)
 *  @description : search the node with the location of i
 *  @param		 : L(the head node),i(the location of node),e(store data)
 *  @return		 : Status
 *  @notice      : None
	*/
Status GetElem(ListN L, int i, ElemType* e);

/**

 *  @name        : int LocateElem(ListN L,ElemType e)
 *  @description : search the location of e
 *  @param		 : L(the head node),e(ElemType)
 *  @return		 : int
 *  @notice      : None
	*/
int LocateElem(ListN L, ElemType e);

/**

 *  @name        : Status InsertElem(ListN L,ElemType e,int i)
 *  @description : insert e into the location of the number of i in linked list
 *  @param		 : L(the head node),e(ElemType),i(the location)
 *  @return		 : Status
 *  @notice      : None
	*/
Status InsertElem(ListN L, ElemType e, int i);

/**

 *  @name        : Status DeleteElem1(ListN L,ElemType e)
 *  @description : delete e in the linked list
 *  @param		 : L(the head node),e(ElemType)
 *  @return		 : Status
 *  @notice      : None
	*/
Status DeleteElem1(ListN L, ElemType e);

/**

 *  @name        : Status DeleteElem2(ListN L,int i)
 *  @description : delete the node of the location of i in the linked list
 *  @param		 : L(the head node),i(the location of node)
 *  @return		 : Status
 *  @notice      : None
	*/
Status DeleteElem2(ListN L, int i);

/**

 *  @name        : Status Exchange(ListN L)
 *  @description : exchange the element of the location of odd_number with the location of even_number
 *  @param		 : L(the head node)
 *  @return		 : Status
 *  @notice      : None
	*/
Status Exchange(ListN L);

/**

 *  @name        : ListN LocateMidpoint(ListN L)
 *  @description : search the midpoint node of linked list
 *  @param		 : L(the head node)
 *  @return		 : ListNode
 *  @notice      : None
	*/
ListN LocateMidpoint(ListN L);

/**

 *  @name        : bool IsCircle_List(ListN L)
 *  @description : check whether the linked list has ciecle
 *  @param		 : L(the head node)
 *  @return		 : bool
 *  @notice      : None
	*/
bool IsCircle_List(ListN L);

/**

 *  @name        : ListN ReverseList1(ListN L)
 *  @description : reverse the linked list
 *  @param		 : L(the head node)
 *  @return		 : ListN
 *  @notice      : None
	*/
ListN ReverseList1(ListN L);

/**

 *  @name        : ListN ReverseList2(ListN pre,ListN cur)
 *  @description : reverse the linked list
 *  @param		 : L(the head node)
 *  @return		 : ListN
 *  @notice      : None
	*/
ListN ReverseList2(ListN pre, ListN cur);

/**

 *  @name        : twoL Init_two_ways_List()
 *  @description : create a two_ways list
 *  @param		 : None
 *  @return		 : twoL
 *  @notice      : None
	*/
twoL Init_two_ways_List();

/**

 *  @name        : Status Create_two_ways_List1(twoL L,int n)
 *  @description : create a two_ways list with n nodes from head to rear
 *  @param		 : L(the head node),n(the number of nodes)
 *  @return		 : Status
 *  @notice      : None
	*/
Status Create_two_ways_List1(twoL L, int n);

/**

 *  @name        : Status Create_two_ways_List2(twoL L,int n)
 *  @description : create a two_ways list with n nodes from rear to head
 *  @param		 : L(the head node),n(the number of node)
 *  @return		 : Status
 *  @notice      : None
	*/
Status Create_two_ways_List2(twoL L, int n);


/**

 *  @name        : Status Destroy_two_ways_List(twoL* L)
 *  @description : destroy the two_ways_List
 *  @param		 : L(the head node)
 *  @return		 : Status
 *  @notice      : None
	*/
Status Destroy_two_ways_List(twoL* L);

/**

 *  @name        : Status Clear_two_ways_List(twoL L)
 *  @description : clear the two_ways_List
 *  @param		 : L(the head node)
 *  @return		 : Status
 *  @notice      : None
	*/
Status Clear_two_ways_List(twoL L);

/**

 *  @name        : int two_ways_LocateElem(twoL L,ElemType e)
 *  @description : search the location of e
 *  @param		 : L(the head node),e(ElemType)
 *  @return		 : int
 *  @notice      : None
	*/
int two_ways_LocateElem(twoL L, ElemType e);

/**

 *  @name        : bool two_ways_IsEmpty(twoL L)
 *  @description : chect whether the two_ways list is empty
 *  @param		 : L(the head node)
 *  @return		 : bool
 *  @notice      : None
	*/
bool two_ways_IsEmpty(twoL L);

/**

 *  @name        : int two_ways_ListLength(twoL L)
 *  @description : count the number of nodes of two_ways_list
 *  @param		 : L(the head node)
 *  @return		 : int 
 *  @notice      : None
	*/
int two_ways_ListLength(twoL L);

/**

 *  @name        : Status GetElem_Prior(twoL L,int i,ElemType* e) 
 *  @description : search the location of i in the two_ways list
 *  @param		 : L(the head node),i(the location of node),e(Elemdata)
 *  @return		 : Status
 *  @notice      : None
    */
Status GetElem_Prior(twoL L, int i, ElemType* e);

/**

 *  @name        : Status InsertElem(twoL L,ElemType e,int i)
 *  @description : insert e into the location of i in the two_ways list
 *  @param		 : L(the head node),e(ElemType),i(the location of node)
 *  @return		 : Status
 *  @notice      : None
	*/
Status InsertElem_two_ways(twoL L, ElemType e, int i);

/**

 *  @name        : Status Delete_two_ways_List1(twoL L,int i)
 *  @description : delete the node of the location of i in the two_ways list
 *  @param		 : L(the head node),i(the location of node)
 *  @return		 : Status
 *  @notice      : None
	*/
Status Delete_two_ways_List1(twoL L, int i);

/**

 *  @name        : Status Delete_two_ways_List2(twoL L,ElemType e)
 *  @description : delete the element of the two_ways_list as the same as e
 *  @param		 : L(the head node),e(ElemType)
 *  @return		 : Status
 *  @notice      : None
	*/
Status Delete_two_ways_List2(twoL L, ElemType e);

/**

 *  @name        : Status CreateCircleList(ListN L,int n)
 *  @description : make the linked list to circle
 *  @param		 : L(the head node),n(the beginning of circle)
 *  @return		 : Status
 *  @notice      : None
	*/
Status CreateCircleList(ListN L, int n);

/**************************************************************

*	End-Multi-Include-Prevent Section
  **************************************************************/
#endif
