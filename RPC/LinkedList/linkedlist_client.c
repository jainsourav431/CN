/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "linkedlist.h"


void
linkedlist_prog_1(char *host,lists list)
{
	CLIENT *clnt;
	void  *result_1;
	lists  addlink_1_arg=list;

#ifndef	DEBUG
	clnt = clnt_create (host, LINKEDLIST_PROG, LINKEDLIST_VERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	result_1 = addlink_1(&addlink_1_arg, clnt);
	if (result_1 == (void *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	else
	{
		node* p =(node*)result_1;
		while(p!=NULL)
		{
			printf("p->data %d \n",p->data);
			p=p->next;
		}
	}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	node *link1,*link2,*temp1,*temp2;
	link1 =(node*)malloc(sizeof(node));
	link2 =(node*)malloc(sizeof(node));
	temp1=link1;
	temp2=link2;
	int n=atoi(argv[2]);
	int i;
	for(i=0;i<n;i++)
	{
		link1->next=(node*)malloc(sizeof(node));
		link1=link1->next;
		link1->data=atoi(argv[3+i]);
		link1->next=NULL;
	}
	for(i=0;i<n;i++)
	{
		link2->next=(node*)malloc(sizeof(node));
		link2=link2->next;
		link2->data=atoi(argv[3+n+i]);
		link2->next=NULL;
	}
	lists list;
	list.l1=temp1->next;
	list.l2=temp2->next;
	linkedlist_prog_1 (host,list);
exit (0);
}
