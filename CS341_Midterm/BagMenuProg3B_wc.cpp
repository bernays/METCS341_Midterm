// John Maslanka  BagMenuProg3-withContainer.cpp Baglist Demo  10/17/2010
// Note: This application contains a delete method to remove a Node from the
//       linked list. This program tests the return value from the new operator.

// Edit:	09/30/2009 Create Bagmenu top-level access to BagList application.
// Edit:	10/17/2010 Complete rewrite of delete method to decouple it from
//          the main.
//			Also fixed bug which caused the end of the list to be lost when a
//			memberin the middle was deleted.
//          Also, suggestions from student Yelena Oulanova to do delete cleanly.
// Edit:	02/15/2012 Changed some method names to more closely
//			reflect the actions of their procedures
// Edit:	02/20/2012 Changed User input from double to string type

using namespace std;

#include "BagMenuProg3B_wc.h"
