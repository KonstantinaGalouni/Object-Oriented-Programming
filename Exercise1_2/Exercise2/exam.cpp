#include <iostream>
#include "functions2.h"
#include <cstdlib>
using namespace std;

extern int MaxIn;
extern int T;
extern int M, MaxRecentTime, MaxTime;



void Exam:: foithtes( )
{
	int i,j;
	st= new Student* [TotalNoofStudents];
		for(i=0; i<TotalNoofStudents; i++)
		{
			int a1= rand( ) % 2;
			int a2= rand( ) % 2;
			int a3= rand( ) % 2;
			st[i]= new Student(i+1, a1, a2, a3);	/* dhmiourgountai kai arxikopoiountai oloi oi foithtes pou paredwsan praktiko meros */
		}



		int ergasia_random= rand( ) % TotalNoofStudents;	/* posa atoma exoun paradwsei ergasia */
		if ((ergasia_random % 2) ==1)						/* elegxos an to parapanw apotelesma einai monos ari8mos */
		{
			ergasia_random-- ;								/* ta atoma pou edwsan ergasia prepei na einai zygos giati h ergasia einai se zeugaria */
		}





		while(ergasia_random > 0)	/* oso yparxoun atoma pou exoun paradwsei praktiko meros */
			{
				int a_m1, a_m2;
				do{
					a_m1= (rand( ) % TotalNoofStudents) +1;		/* oi ari8moi mhtrou einai to synolo [1,TotalNoofStudents] ara dikaologeitai to +1 */
				}while (st[a_m1- 1]->ergasia( ) == 1);
				/* psaxnei tyxaia ari8mous mhtroou oso briskei autous pou hdh exoun epilegei tyxaia */

				st[a_m1- 1]->set_ergasia( );	//enhmerwnei oti o foithths exei kanei ergasia */


				do{
					a_m2= rand( ) % (TotalNoofStudents) +1;		/* psaxnei tyxaia ki allo ari8mo mhtroou gia na brei ton symfoithth tou prwtou */
				}while (st[a_m2- 1]->ergasia( ) == 1);



				//st[a_m1- 1]->set_ergasia( );
				st[a_m2- 1]->set_ergasia( );
				st[a_m1- 1]->set_with(a_m2);	/* syndeei tous foithtes pou synergasthkan gia thn ergasia */
				st[a_m2- 1]->set_with(a_m1);

				int who;
				if((rand( ) % 2)== 0)
				{
					who= a_m1;		/* epilegei tyxaia poios apo tous 2 paredwse thn ergasia */
				}
				else
				{
					who= a_m2;
				}
				st[a_m1- 1]->set_bw(who);
				st[a_m2 -1]->set_bw(who);

				ergasia_random= ergasia_random - 2;		/* prepei na bre8oun akoma tyxaia oi ari8moi mhtrou oswn */
														/* foithtwn edwsan ergasia - tous 2 pou bre8hkan twra */
			}







		int osoi_exoun_ftasei = 0;		/* osoi exoun eksetastei kai osoi perimenoun sthn ekswterikh oura h thn oura tou */
											/* antistoixou Synergath pou tous eksetazei */
		int time = 0;						/* metrietai se lepta o xronos */


		int rounds = 0;						/* kykloi pou exoun ginei */


		List::Iterator it00 = NULL;
		List::Iterator it0 = NULL;
		List::Iterator it1 = NULL;
		List::Iterator it = NULL;


		while(time <= ((8*60)-T))		/* syn8hkh gia ton ari8mo twn kyklwn pou 8a ginoun */
		{
			 if(osoi_exoun_ftasei == TotalNoofStudents)		/* an exoun er8ei oloi oi foithtes */
				 break;


			 int random_s[4];	/* gia ka8e synergath posoi foithtes eksetazontai sto sygkekrimeno kyklo */
			 int ftanoun_twra =rand( ) % (TotalNoofStudents-osoi_exoun_ftasei);	/* se auton ton kyklo ftanoun autoi oi foithtes */



			 for(i=osoi_exoun_ftasei; i< osoi_exoun_ftasei + ftanoun_twra; i++)
			 {

					it00 =oura[0]-> insert(*st[i]);		/* pairnei enan enan tous foithtes kai tous bazei sthn ekswterikh oura ektos apo thn parapanw periptwsh */




					if(it00.data( ).ergasia( ) == 0)			/* an den exei kanei ergasia */
						it00.data( ).set_flag_ergasia(1);		/* ton antimetwpizoume san na ekane kai na exei hdh exetastei gi'authn */
					else
						it00.data( ).set_flag_ergasia(0);

					if((it00.data( ).ergasia( ) == 0) && (it00.data( ).askhseis( ) == 0))	/* an den exei kanei oute askhseis oute ergasia */
						it00.data( ).set_ask1( );		/* bazoume by default na exei kanei thn 1h askhsh, dioti prepei na exei opwsdhpote paradwsei praktiko meros */

					if(it00.data( ).askhseis( ) == 0)			/* an den exei kanei askhseis */
						it00.data( ).set_flag_askhseis(1);	/* ton antimetwpizoume san na ekane kai na exei hdh eksetastei gi'autes */
					else
						it00.data( ).set_flag_askhseis(0);


					it00.data( ).couts( );					/* ektypwnei ta stoixeia ka8e foithth */
					cout<< "Arriving!" <<endl<< endl;
					it00.data( ).set_exei_ftasei(1);			/* enhmerwnei oti einai sto xwro eksetashs */
					it00.data( ).set_is_here(1);				/* o foithths einai edw. Den krataei th 8esh enw leipei */





					if(it00.data( ).give_with( ) != 0)
						/* elegxei gia ka8e foithth pou eiserxetai sto xwro eksetashs an exei symfoithth, dhladh an exei kanei ergasia */
					{
						it00.data( ).set_exei_ftasei_partner( st[it00.data( ).give_with( ) -1]-> get_exei_ftasei( ) );
					/*An nai elegxei an exei ftasei o symfoithths tou kai to apotelesma to topo8etei sto data member exei_ftasei_partner */
					}
					else
						it00.data( ).set_exei_ftasei_partner(0);
					/* An oxi tote enhmerwnei oti o symfoithths den exei ftasei (afou den yparxei symfoithths) */


					if((it00.data( ).ergasia( ) ==1) && (it00.data( ).get_exei_ftasei_partner( ) == 1) && (it00.data( ).give_bw( ) == st[it00.data( ).give_with( )]->ar_m( )))
						/* an o foithths exei kanei ergasia kai exei ftasei o symfoithths tou kai o symfoithths exei paradwsei thn ergasia */
					{

						for(j=0; j<4; j++)	/* gia ka8e enan apo tous 4 synergates */
						{
							if(s[j]->l.find(*st[it00.data( ).give_bw( ) -1]).container( ) != NULL )
		/* an bre8ei o symfoithths  tou foithth pou mphke twra, sthn oura se kapoia oura twn 4 synergatwn */
								it00.data( ).set_is_here(0);	/*8etw oti o foithths de brisketai proswrina sthn oura pou molis mphke */
						}

					}
			 }


				osoi_exoun_ftasei= osoi_exoun_ftasei + ftanoun_twra;
				time=time+T;		/* o synolikos xronos eksetashs auksanetai kata to xrono tou kyklou pou ginetai twra */
				rounds++;			/* oi kykloi pou exoun ginei */



/* **************************** */


				int random;
				random= rand( ) % TotalNoofStudents;	/* tyxaios ari8mos foithtwn pou 8a eksetastei efoson einai efikto apo ton synergath se auton ton kyklo */

				for(i=0; i<4; i++)
				{
					random_s[i]=0;
					it1=oura[1]->begin( );
					while(it1.container( ) != NULL)	/* oso yparxoun foithtes ektos ouras pou perimenoun na eksetastoun gia ergasia */
					{
						if(s[i]->l.find(*st[it1.data( ).give_with( ) -1]).container( ) == NULL)	/* an den yparxei sthn oura tou synergath o symfoithths
											,pou paredwse thn ergasia, tou foithth pou perimenei na eksetastei gia thn ergasia ektos ouras*/
						{
								it1.data( ).set_flag_ergasia(1);	/* shmeiwnetai oti o foithths eksetasthke gia thn ergasia */
								if(it1.data( ).askhseis( ) == 0)	/* an den exei kanei askhseis */
								{
									if(random >0)
									{
										random--;		/* metrame oti eksetasthke kai o foithths autos, afou de 8a eksetastei apo allo synergath */
										random_s[i]++;
									}
								}
						}
						cout<< it1.data( ).ar_m( ) <<endl;		/* ektypwnontai ta stoixeia tou foithth pou molis eksetasthke ektos ouras */
						cout<< "Completed!"<< endl<< endl;
						List:: Iterator tempor = it1;
						oura[1]->remove(tempor.data( ));		/*o foithths pou molis eksetasthke apoxwrei */
						/* kapws prepei na poume sto symfoithth pou molis apoxwrhse oti o teleutaios den exei ftasei */
						it1.next( );
					}

				}


	/* ******************************************** */


				for(i=0; i<4; i++)
				{
					it = s[i]->l.begin();
					it1 = oura[1]->begin( );

					while((random > 0) && ((it.container( ) != NULL) || (it1.container( )!= NULL)))
					{

						s[i]->synol_diark_ex++ ;

						if(s[i]->l.size( )==0)		/* an den yparxoun foithtes sthn oura tou Synergath */
						{
							break;
						}
						else						/* an yparxoun foithtes sthn oura tou synergath */
						{
							if(it.data( ).give_bw( ) == it.data( ).ar_m( ))	/* an o foithths exei paradwsei kai thn ergasia */
							{
								it.data( ).set_flag_ergasia(1);		/* shmeiwnetai oti o foithths eksetasthke gia thn ergasia */

								if(oura[1]->find(*st[it.data( ).give_with( ) -1]).container( ) != NULL)
									/* an brei to symfoithth tou foithth, pou eksetazetai kanonika, ektos ouras */
								{
									for(j=0; j<4; j++)
									{

										if(i==j)	/* den yparxei logos na psaksoume na broume to symfoithth tou foithth pou eksetazetai sthn idia oura me to foithth pou eksetazetai */
											continue;
										if(s[j]->l.find(*st[it.data( ).give_with( ) -1]).container( ) != NULL )
											/* an brei to symfoithth sth oura allou synergath */
										{
											List:: Iterator temp = s[j]->l.find(*st[it.data( ).give_with( ) -1]);
											temp.data( ).set_flag_ergasia(1);	/* o symfoithths autou pou eksetazotan kanonika eksetasthke gia thn ergasia */
											temp.data( ).set_is_here(1);
											oura[1]->remove(temp.data( ));
											break;
										}
									}

									if(oura[0]->find(*st[it.data( ).give_with( ) -1]).container( ) != NULL)
										/* an brei to symfoithth sthn arxikh oura */
									{
										List:: Iterator temp = oura[0]->find(*st[it.data( ).give_with( ) -1]);
										temp.data( ).set_flag_ergasia(1);
										temp.data( ).set_is_here(1);
										oura[1]->remove(temp.data( ));
										oura[1]->remove(*st[it.data( ).give_with( ) -1]);	/* o symfoithths apomakrynetai apo thn oura opou perimene na eksetastei gia thn ergasia */
									}
								}


								if(oura[1]->find(*st[it.data( ).give_with( ) -1]).container( ) != NULL)
									/* an o symfoithths einai akoma sthn oura gia thn eksetash ths ergasias */
								{
									List:: Iterator temp = oura[1]->find(*st[it.data( ).give_with( ) -1]);
									temp.data( ).set_flag_ergasia(1);
									temp.data( ).set_flag_askhseis(1);
									int with_tmp = temp.data( ).ar_m( );
									with_tmp = with_tmp % 10;	/* lhgontas ari8mou mhtroou tou symfoithth pou brhkame sthn oura[1] */
									if((temp.data( ).askhseis( ) == 0) || ((with_tmp == s[i]->get_lhg1( )) || (with_tmp == s[i]->get_lhg2( )) || (with_tmp == s[i]->get_lhg3( ))))
										/* an o symfoithths den eixe kanei kamia askhsh h eksetazetai apo ton idio synergath me to symfoithth tou me bash to lhgonta tou */
									{
										if(random > 0)
											{
												random--;		/* metrame oti eksetasthke kai o foithths autos, afou de 8a eksetastei apo allo synergath */
												random_s[i]++;
											}
									}
									cout<< temp.data( ).ar_m( ) <<endl;		/* ektypwnontai ta stoixeia tou symfoithth pou molis eksetasthke */

									cout<< "Completed!"<< endl<< endl;
									oura[1]->remove(temp.data( ));			/* o symfoithths apomakrynetai apo thn oura pou perimene na eksetastei gia thn ergasia */
								}
							}

							if(it.data( ).get_is_here( ) == 1)
							{
								it.data( ).set_flag_askhseis(1);	/* shmeiwnetai oti o foithths eksetasthke gia tis askhseis */
								if(it.data( ).get_flag_ergasia( ) == 1)
								{
									cout<< it.data( ).ar_m( ) <<endl;		/* ektypwnontai ta stoixeia tou foithth pou molis eksetasthke */
									cout<< "Completed!"<< endl<< endl;
									if(it.data( ).give_with( ) != 0)
									{
										if(oura[0]->find(*st[it.data( ).give_with( ) -1]).container( ) != NULL)
										{
											List:: Iterator iterator= oura[0]->find(*st[it.data( ).give_with( ) -1]);
											iterator.data( ).set_exei_ftasei_partner(0);
										}
									}
								}
								if(it.data( ).get_flag_ergasia( ) == 0)	/* an den exei eksetastei gia thn ergasia tou */
									oura[1]->insert(it.data( ));
								s[i]->l.remove(it.data( ));			/* o foithths apomakrynetai apo th lista tou synergath pou ton eksetase */

								if(random >0)
								{
									random--;		/* 8a eksetastoun akoma apo to synergath random foithtes */
									random_s[i]++;
								}
							}


							if(it.container( )!= NULL)
								it.next( );				/* 8a melethsoume ton epomeno foithth */
							if(it1.container( )!=NULL)
								it1.next( );
						}


					}
					s[i]->n_of_ex_st = s[i]->n_of_ex_st + random_s[i];	/* foithtes pou eksetasthkan apo to synergath */
					if(s[i]->n_of_ex_st != 0)

						s[i]->tps = (rounds * T) / s[i]->n_of_ex_st ; 	/* mesos xronos proforikhs eksetashs foithth */

					else
						cout<< "kanenas foithths den exei eksetastei apo to synergath "<<i <<endl;
				}


				it0=oura[0]->begin( );


				while(it0.container( ) != NULL)	/* mexri na prospelasoume oloklhrh thn oura */
				{
					if((it0.data( ).get_is_here( ) == 0) && (it0.data( ).get_exei_ftasei_partner( ) == 0))
						/* an krataei th 8esh enw leipei proswrina kai o synergaths tou den einai se kapoia oura
						dhladh o synergaths eksetasthke sto sygkekrimeno kyklo kai efyge */
					{
						it0.data( ).set_is_here(1);
					}

					else if((it0.data( ).get_is_here( ) == 0) && (it0.data( ).get_exei_ftasei_partner( ) == 1))
					{
						oura[1]->insert(it0.data( ));
					}
					it0.next( );	/* elegxoume ton epomeno foithth sthn oura */
				}



				it0 = oura[0]->begin( );

				while(((s[0]->l.size( ) < MaxIn) || (s[1]->l.size( ) < MaxIn) || (s[2]->l.size( ) < MaxIn) || (s[3]->l.size( ) < MaxIn)) && (it0.container( ) != NULL))
					/* oso yparxei xwros stis listes twn synergatwn kai den exoume melethsei olous tous foithtes ths ekswterikhs ouras */
				{
					int a_m_tmp = it0.data( ).ar_m( );
					a_m_tmp = a_m_tmp % 10;				/*lhgontas ari8mou mhtroou */

					for(i=0; i<4; i++)		/* gia tous 4 synergates */
					{
						if((s[i]->l.size( ) <MaxIn) && ((a_m_tmp == s[i]->get_lhg1( )) || (a_m_tmp == s[i]->get_lhg2( )) || (a_m_tmp == s[i]->get_lhg3( ))))
						/* an yparxei xwros sthn oura tou sygkekrimenou synergath kai o lhgontas tou foithth pou meletame tou antistoixei */
						{
							if(it0.data( ).get_is_here( ) == 1)
							{
								s[i]->l.insert(it0.data( ));	/* sthn oura tou synergath ftiaxnetai neos komvos sto telos opou prosti8etai o foithths */
								cout<< "Entering "<< it0.data( ).ar_m( ) << ", Synergaths: "<< s[i]->get_name( ) <<endl;

								if(it0.data( ).give_bw( ) == it0.data( ).ar_m( ))	/* an o foithths pou molis mphke sthn oura tou synergath pou ton eksetazei paredwse thn ergasia */
								{
									for(j=0; j<4; j++)
									{
										if(s[j]->l.find(*st[it0.data( ).give_with( ) -1]).container( ) != NULL )
										/* an bre8ei se kapoia apo tis oures twn synergatwn o symfoithths tou foithth pou molis mphke sthn oura tou synergath tou */
										{
											List:: Iterator temp = s[j]->l.find(*st[it0.data( ).give_with( ) -1]);

											oura[1]->insert(temp.data( ));

											if(i==j)
											{
												s[j]->l.remove(temp.data( ));
												break;
											}
											else
												temp.data( ).set_is_here(0);	/* 8etoume oti leipei proswrina apo thn oura pou ton brhkame */
											break;
										}
									}

									if(oura[0]->find(*st[it0.data( ).give_with( ) -1]).container( ) != NULL)
									{
										List:: Iterator temp = oura[0]->find(*st[it0.data( ).give_with( ) -1]);

										oura[1]->insert(temp.data( ));

										int with_tmp = it0.data( ).give_with();
										with_tmp = with_tmp % 10;	/* lhgontas ari8mou mhtroou tou symfoithth pou brhkame sthn oura[0] */
										if(((with_tmp == s[i]->get_lhg1( )) || (with_tmp == s[i]->get_lhg2( )) || (with_tmp == s[i]->get_lhg3( ))) || (st[it0.data( ).give_with( ) -1]) == 0)
											oura[0]->remove(temp.data( ));
										else
											temp.data( ).set_is_here(0);
									}
								}

								oura[0]->remove(it0.data( ));
								it0.next( );		/* o epomenos pou 8a melethsoume einai o epomenos ths ekswterikhs ouras */
								break;
							}
						}
					}
				}


				 it0 = oura[0]->begin( );
				 while(it0.container( ) != NULL)
				 {
					 if((it0.data( ).askhseis( ) == 0) && (it0.data( ).ar_m( ) != it0.data( ).give_bw( )))
					/* an o foithths pou einai h seira tou na mpei sthn oura den exei kanei askhseis kai den exei paradwsei autos thn ergasia */
					 {
						 oura[1]-> insert(it0.data( ));	/* tote paei sthn ekswterikh oura na perimenei na eksetastei gia ergasia apo to synergath tou symfoithth tou */
						 List::Iterator iter = it0;
						 oura[0]->remove(iter.data( ));
					 }
					 it0.next( );
				 }




				for(i=0; i<4; i++)	/* gia ka8e enan apo tous 4 synergates */
				{
					while(it.container( ) != NULL)	/* oso den exoume melethsei kai ton teleutaio foithth sthn oura tou synergath */
					{
						if((it.data( ).get_flag_askhseis( ) ==1) && (it.data( ).get_flag_ergasia( ) == 0))
						{
							oura[1]->insert(it.data( ));	/* bale ton foithth sthn ekswterikh oura na perimenei na eksetastei gia thn ergasia tou */
							List:: Iterator tempor = it;
							s[i]->l.remove(tempor.data( ));		/* apomakryne to foithth apo thn oura tou synergath */
						}
					it.next( );	/* melethse ton epomeno foithth */
					}

				}


/* teleutaio stadio proforikhs eksetashs */
				for(i=0; i<4; i++)
				{
					int waiting=0;
					int Quant=2;

					it0 = NULL;
					if(oura[0]->size( ) > 0)
					it0 = oura[0]->begin( );
					while(it0.container( ) != NULL)
					{
						int a_m_tmp;
						a_m_tmp = it0.data( ).ar_m( );
						a_m_tmp = a_m_tmp % 10;
						if((a_m_tmp == s[i]->get_lhg1( )) || (a_m_tmp == s[i]->get_lhg2( )) || (a_m_tmp == s[i]->get_lhg3( )))
							waiting++;
						it0.next( );
					}
					if(s[i]->get_lhg3( ) == -1)
					{
						if(s[i]->get_lhg2( ) == -1)
							Quant = 1;
						else
							Quant = 1.5;
					}

					M = M* Quant;

					if((s[i]->tps > MaxTime) || ((waiting >= M) && (s[i]->tpsl > MaxRecentTime)))
							cout<< s[i]->get_name( ) << " please, hurry up" << endl;
				}


				for(i=0; i<4; i++)
				{
					if(random_s[i] > 0)
							s[i]->synol_diark_ex++ ;
				}

		}/* telos proforikhs eksetashs */



		if(((time + T) > (8*60)) &&  (osoi_exoun_ftasei < TotalNoofStudents))
			/* an den exoun eisel8ei oloi oi foithtes pou paredwsan praktiko meros */
			for(i=osoi_exoun_ftasei; i < TotalNoofStudents; i++)
			{
				oura[0]-> insert (*st[i]);		/* pairnei enan enan tous foithtes kai tous bazei sthn ekswterikh oura ektos apo thn parapanw periptwsh */
				st[i]->couts( );					/* ektypwnei ta stoixeia ka8e foithth */
				cout<< "Arriving!" <<endl<< endl;
				st[i]->set_exei_ftasei(1);			/* enhmerwnei oti einai sto xwro eksetashs */
			}


}


