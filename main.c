/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 11:01:33 by eprusako          #+#    #+#             */
/*   Updated: 2020/10/15 16:45:58 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <limits.h>

int		main(void)
{
/* 	char *str;
	char *a;
	char *b;
	char *c;
	char *d; */
	int i;

/* 	str = "Hello";
	i = 5;
	a = "AA";
	b ="BB";
	c ="\0CCCC";
	d = "DDDDDDD";
	static char 		ch_pos_1 = 100, ch_neg_1 = -87;
static short		sh_pos_1 = 3047, sh_neg_1 = -8875;
static int			i_pos_1 = 878023;
static long			l_pos_1 = 22337203685477, l_neg_1 = -22337203685477;
static long long	ll_pos_1 = 22337203685477, ll_neg_1 = -22337203685477;
static long			lmax	= 9223372036854775807;
static long			lmin	= -9223372036854775807;
static long long	llmax = 9223372036854775807;
static long long	llmin = -9223372036854775807ll; */
/*
		printf(" print %05%\n");
	 ft_printf("fprint %05%\n");

	printf("%#o\n", 42);
	ft_printf("%#o\n", 42);

	   printf("%#O\n", 3);
	ft_printf("%#O\n", 3);
*/
/* 	printf("%");
	ft_printf("%");
 */
/*
printf("{%-5d}\n", 14);
ft_printf("{%-5d}\n", 14);

printf("{%-5d}\n", -4444);
ft_printf("{%-5d}\n", -4444);
 */

/* printf("{%10.5d}\n", -216);
ft_printf("{%10.5d}\n", -216);

  printf("{%5.0d}\n", 0);
ft_printf("{%5.0d}\n", 0);
 */
/*
printf("%+5.0i|\n", 0);
ft_printf("%+5.0i|\n", 0);


printf("{%*i}\n", -14, 94827);
ft_printf("{%*i}\n", -14, 94827);

printf("{%%04.5i 42 == |%04.5i|}\n", 42);
ft_printf("{%%04.5i 42 == |%04.5i|}\n", 42);
 */

printf("%010x|\n", 542);
  ft_printf("%010x|\n", 542);

 printf("%#-08x|\n", 42);
ft_printf("%#-08x|\n", 42);


/* i = printf("%d|", 1);
printf("\n%d\n", i);F
i = ft_printf("%d|", 1);
printf("\n%d\n", i);
printf("\n"); */

/*
  printf("%#6o|\n", 2500);
  ft_printf("%#6o|\n", 2500);

  printf("%-#6o|\n", 2500);
  ft_printf("%-#6o|\n", 2500);

  printf("%-05o|\n", 2500);
  ft_printf("%-05o|\n", 2500);

  printf("%-5.10o|\n", 2500);
  ft_printf("%-5.10o|\n", 2500);

  printf("%03.2d|\n", -1);
  ft_printf("%03.2d|\n", -1);
    printf("%03.2d|\n", -4);
  ft_printf("%03.2d|\n", -4);
 */

 printf("{%08.5x}\n", 42);
ft_printf("{%08.5x}\n", 42);

 printf("{%08.5u}\n", 42);
ft_printf("{%08.5u}\n", 42);
/*
 printf("{% +-10.5d}\n", 114242);
ft_printf("{% +-10.5d}\n", 114242);

 printf("{% +-10.5u}\n", 114242);
ft_printf("{% +-10.5u}\n", 114242);

 printf("{%+10.5u}\n", 114242);
ft_printf("{%+10.5u}\n", 114242);

 printf("{% -10.5u}\n", 114242);
ft_printf("{% -10.5u}\n", 114242);

 printf("{% 10.5u}\n", 114242);
ft_printf("{% 10.5u}\n", 114242);

printf("%-4d", 94827);
ft_printf("%-4d", 94827);


printf("{%-04d}\n", 94827);
ft_printf("{%-04d}\n", 94827);
 */
/*
printf("{%4d}\n", 11111111);
ft_printf("{%4d}\n", 11111111);
 */
/*
printf("{%10d}\n", 4);
ft_printf("{%10d}\n", 4);

printf("{%10d}\n", -4);
ft_printf("{%10d}\n", -4);

printf("{%10d}\n", +4);
ft_printf("{%10d}\n", +4);


printf("{% 10d}\n", 4);
ft_printf("{% 10d}\n", 4);

printf("{%+10d}\n", 4);
ft_printf("{%+10d}\n", 4);

 printf("{%0+5d}\n", 42);
ft_printf("{%0+5d}\n", 42);

 printf("{%0+5d}\n", -42);
ft_printf("{%0+5d}\n", -42);



 printf("{%+10.5d}\n", -216);
ft_printf("{%+10.5d}\n", -216);

 printf("{%0+5d}\n", -42);
ft_printf("{%0+5d}\n", -42);


 printf("{%.d %.0d}\n", 42, 43);
ft_printf("{%.d %.0d}\n", 42, 43);

   printf("{%+.0d}\n", 0);
ft_printf("{%+.0d}\n", 0);

   printf("{%-.0d}\n", 0);
ft_printf("{%-.0d}\n", 0);


   printf("{%010.5d}\n", -216);
ft_printf("{%010.5d}\n", -216);

   printf("{%03.2d\n", -1);
ft_printf("{%03.2d\n", -1);

   printf("{%+3.3d}\n", 6983);
ft_printf("{%+3.3d}\n", 6983);

   printf("{%+-3.7d}\n", 3267);
ft_printf("{%+-3.7d}\n", 3267);


printf("\n TEST \n");
   printf("{%+10.5d}\n", 004242);
ft_printf("{%+10.5d}\n", 004242);

   printf("{%+10.5d}\n", 114242);
ft_printf("{%+10.5d}\n", 114242);

   printf("{% +10.5d}\n", 114242);
ft_printf("{% +10.5d}\n", 114242);

   printf("{% +-10.5d}\n", 114242);
ft_printf("{% +-10.5d}\n", 114242);

printf("{%+ d}\n", 42);
ft_printf("{%+ d}\n", 42);



 printf("{%#6o}\n", 2500);
ft_printf("{%#6o}\n", 2500);

 */
/*
	printf("test to lose your mind\n");
	printf("print |%-05%|\n");
	 ft_printf("print |%-05%|\n");
 */
	/*    printf("|realpri |%10.2s| |%5.1s| |%3.0s| |%6.10s|\n", str, str, str, str);
	ft_printf("|myprint |%10.2s| |%5.1s| |%3.0s| |%6.10s|\n", str, str, str, str);
 */


/* printf("%030.3d|", 8375);
	   printf("\n");
	ft_printf("%030.3d|\n", 8375);
 printf("\n");
	printf("%08.3d|", 8375);
	   printf("\n");
	ft_printf("%08.3d|\n", 8375);
 printf("\n");

 	printf("%0-8.3d|", 8375);
	   printf("\n");
	ft_printf("%0-8.3d|\n", 8375);
 printf("\n");
 */
/*
 	printf("%lld", 9223372036854775807);
	   printf("\n");
 ft_printf("%lld\n", 9223372036854775807);

 	printf("%ld", 9223372036854775807);
	   printf("\n");
 ft_printf("%ld\n", 9223372036854775807);

 	printf("%Ld", 9223372036854775807);
	   printf("\n");
 ft_printf("%Ld\n", 9223372036854775807);

 */

/* 	printf("h flag\n");
	printf("% hd", (short)(-32768));
	   printf("\n");
 ft_printf("% hd\n", (short)(-32768));


	printf("hh flag\n");
 printf("%hhd", (signed char)(-32768));
	   printf("\n");
 ft_printf("%hhd\n", (signed char)(-32768));


 printf("%hhd", (signed char)(-32768));
	   printf("\n");
 ft_printf("%hhd\n", (signed char)(-32768));


 printf("% hhd", (char)(-32));
	   printf("\n");
 ft_printf("% hhd\n", (char)(-32));
 */
/*
	printf("minus values\n\n");
	printf("%i%lli%hhi", i_pos_1, ll_neg_1, ch_pos_1);
	   printf("\n\n");
 ft_printf("%i%lli%hhi\n\n", i_pos_1, ll_neg_1, ch_pos_1);


	printf("llu flag\n\n");
 printf("%llu", 9223372036854775807);
	   printf("\n\n");
 ft_printf("%llu\n", 9223372036854775807);
 */
/*
 printf("%hhd", (signed char)(-32768));
	   printf("\n");
 ft_printf("%hhd\n", (signed char)(-32768));


 printf("% hhd", (char)(-32));
	   printf("\n");
 ft_printf("% hhd\n", (char)(-32));
 */
/* 	printf("j flag\n");
printf("%jd", 9223372036854775807);
	   printf("\n");
 ft_printf("%jd\n", 9223372036854775807);

 printf("%zd", 9223372036854775807);
	   printf("\n");
 ft_printf("%zd\n", 9223372036854775807);

 printf("%td", 9223372036854775807);
	   printf("\n");
 ft_printf("%td\n", 9223372036854775807);
 */
/*  printf("\n");
	printf("%X|", 2375);
	   printf("\n");
	ft_printf("%X|\n\n", 2375);

 printf("\n");
	printf("%X|", -2375);
	   printf("\n");
	ft_printf("%X|\n\n", -2375);

 printf("\n");
	printf("%07x", -14);
	   printf("\n");
	ft_printf("%07x", -14);

 printf("\n");
	 printf("%.*X", -1, 12345);
	   printf("\n");
	ft_printf("%.*X\n", -1, 12345);
 */

/*  printf("%#08.3x|", 8375);
	   printf("\n");
	ft_printf("%#08.3x|", 8375);
	printf("\n");
 printf("\n");

  printf("%#08.5X", 34);
	   printf("\n");
	ft_printf("%#08.5X", 34);
	printf("\n");
 printf("\n");
 */
/*  printf("%#x", 3);
	   printf("\n");
	ft_printf("%#x", 3);
	printf("\n");
 printf("\n");
 */
/* 	 printf("%#8.5x", 34);
	   printf("\n");
	ft_printf("%#8.5x", 34);
	printf("\n");
 printf("\n");

 printf("%#05x", 43);
	   printf("\n");
	ft_printf("%#05x", 43);
	printf("\n");
 printf("\n");

	printf("%#3x", 0);
	   printf("\n");
	ft_printf("%#3x", 0);
 printf("\n");
 printf("\n");
	printf("%#5.x|", 0);
	   printf("\n");
	ft_printf("%#5.x|", 0);
 printf("\n");
 printf("\n");
	printf("%#03x", 0);
	   printf("\n");
	ft_printf("%#03x", 0);
 printf("\n");
 printf("\n");
	 printf("%#8.5x", 34);
	   printf("\n");
	ft_printf("%#8.5x", 34);
 printf("\n");
 printf("\n");
	 printf("%#08.5x", 0);
	   printf("\n");
	ft_printf("%#08.5x", 0);
	printf("\n"); */
/*
 printf("\n");
	printf("%O|", 2375);
	   printf("\n");
	ft_printf("%O|\n\n", 2375);

 printf("\n");
	printf("%o|", -2375);
	   printf("\n");
	ft_printf("%o|\n\n", -2375);

 printf("\n");
	printf("%07o", -14);
	   printf("\n");
	ft_printf("%07o", -14);


printf("{ %#.o %#.0o}\n", 0, 0);
ft_printf("{ %#.o %#.0o}\n", 0, 0);


 printf("\n");
	 printf("%.*O", -1, 12345);
	   printf("\n");
	ft_printf("%.*O\n", -1, 12345);

	 printf("\n");π
	printf("%u|", 2375);
	   printf("\n");
	ft_printf("%u|\n\n", 2375);

 printf("\n");
	printf("%u|", -2375);
	   printf("\n");
	ft_printf("%u|\n\n", -2375);

 printf("\n");
	printf("%07u", -14);
	   printf("\n");
	ft_printf("%07u", -14);

 printf("\n");
	 printf("%.*u", -1, 12345);
	   printf("\n");
	ft_printf("%.*u\n", -1, 12345);
 */
/*
	 printf("\n");
	printf("%i|", -2147483648);
	   printf("\n");
	ft_printf("%i|\n\n", -2147483648);

 printf("\n");
	printf("%u|", -2375);
	   printf("\n");
	ft_printf("%u|\n\n", -2375);


 printf("\n");
	printf("%0*i|", -7, -54);
	   printf("\n");
	ft_printf("%0*i|", -7, -54);

 printf("\n");
	printf("%i", 2147483658);
	   printf("\n");
	ft_printf("%i",2147483658);

 printf("\n");
	printf("%0*i", 7, -54);
	   printf("\n");
	ft_printf("%0*i", 7, -54);

 printf("\n");
	printf("%*i", -4, 94827);
	   printf("\n");
	ft_printf("%*i", -4, 94827); */
/*
	printf("%-*s|\n", 32, "abc");
	ft_printf("%-*s|\n", 32, "abc"); */
/*
	printf("%-*.*s|\n", -7, -3, "yolo");
	ft_printf("%-*.*s|\n", -7, -3, "yolo");

	    printf("|%s|\n", "|Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Etalafinilla*bip*|");
	  ft_printf("|%s|\n", "|Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Etalafinilla*bip*|");

	 printf("\n");
	printf("%% *.5i 42 == |% *.5i|", 4, 42);
	   printf("\n");
	ft_printf("%% *.5i 42 == |% *.5i|\n", 4, 42); */

/* printf("'%.5f'", 99.999999);
printf("\n");
ft_printf("'%.5f'", 99.999999);
printf("\n");
 */


/* FLOATTTTTTTT */

/*
printf("% 0-8.5i|\n", 0 );
ft_printf("% 0-8.5i|\n", 0 );
 */



 printf("\t test start \n");


i = printf("real %f\n", 1.0);
printf("%d\n", i);
printf("\n");
i = ft_printf("my   %f\n", 1.0);
printf("%d\n", i);
printf("\n");














/*
printf("\t test start \n");
printf("%f", -7.5);
printf("\n");
ft_printf("%f", -7.5);
printf("\n");
printf("\n");
 */
/* printf("\t test start \n");
printf("%f", -0.0);
printf("\n");
ft_printf("%f", -0.0);
printf("\n");
printf("\n");

printf("\t test start \n");
printf("%f", 0.0);
printf("\n");
ft_printf("%f", 0.0);
printf("\n");
printf("\n");
 */
/* printf("\t test start \n");
printf("%f", 9873.000001);
printf("\n");
ft_printf("%f", 9873.000001);
printf("\n");
printf("\n");
 */

/* printf("\t test start \n");
printf("%f", -56.2012685);
printf("\n");
ft_printf("%f", -56.2012685);
printf("\n");
printf("\n");
 */

/*
printf("\t test start \n");
printf("%.20f", 3.12345);
printf("\n");
ft_printf("%.20f", 3.12345);
printf("\n");
printf("\n");

printf("\t test start \n");
printf("%f", -5.9999);
printf("\n");
ft_printf("%f", -5.9999);
printf("\n");
printf("\n");
 */
/*
printf("P 0.15 %.1f\n", 0.15);
printf("P 0.25 %.1f\n", 0.25);
printf("P 0.35 %.1f\n", 0.35);
printf("P 0.45 %.1f\n", 0.45);
printf("P 0.55 %.1f\n", 0.55);
printf("P 0.65 %.1f\n", 0.65);
printf("P 0.75 %.1f\n", 0.75);
printf("P 0.85 %.1f\n", 0.85);
printf("P 0.95 %.1f\n", 0.95);
printf("P 0.555 %.2f\n", 0.555);
printf("\n");
ft_printf("P 0.15 %.1f\n", 0.15);
ft_printf("P 0.25 %.1f\n", 0.25);
ft_printf("P 0.35 %.1f\n", 0.35);
ft_printf("P 0.45 %.1f\n", 0.45);
ft_printf("P 0.55 %.1f\n", 0.55);
ft_printf("P 0.65 %.1f\n", 0.65);
ft_printf("P 0.75 %.1f\n", 0.75);
ft_printf("P 0.85 %.1f\n", 0.85);
ft_printf("P 0.95 %.1f\n", 0.95);
ft_printf("P 0.555 %.2f\n", 0.555);

printf("\t test start \n");
printf("%.f", -3.5);
printf("\n");
ft_printf("%.f", -3.5);
printf("\n");
printf("\n");

printf("\t test start \n");
printf("%.0f", 2.5);
printf("\n");
ft_printf("%.0f", 2.5);
printf("\n");
printf("\n");
 */
/* printf("\t test start \n");
printf("%.0f", 573.924);
printf("\n");
ft_printf("%.0f", 573.924);
printf("\n");
printf("\n");
 */
/* printf("\t test start \n");
printf("%.0f", -0.0);
printf("\n");
ft_printf("%.0f", -0.0);
printf("\n");
printf("\n");
 */

/* printf("P #.0f %#.0f|\n", 0.0);
printf("P #.0f %+.0f|\n", 0.0);

ft_printf("P #.0f %#.0f|\n", 0.0);
ft_printf("P +.0f %+.0f|\n", 0.0);
 */
/*
printf("P -0.999 %.0f\n", -0.999);
ft_printf("P -0.999 %.0f\n", -0.999);
 */
/* i =    printf("P * %.*f\n", -1, 3.1415926535);
printf("%d", i);
printf("\n");
i = ft_printf("P * %.*f\n", -1, 3.1415926535);
ft_printf("%d", i); */


/* printf("P 0.35 %.1f\n", 0.35);
printf("P 0.45 %.1f\n", 0.45);
printf("P 0.55 %.1f\n", 0.55);
printf("P 0.65 %.1f\n", 0.65);
printf("P 0.75 %.1f\n", 0.75);
printf("P 0.85 %.1f\n", 0.85);
printf("P 0.95 %.1f\n", 0.95);
printf("P 0.555 %.2f\n", 0.555); */
printf("\n");

/* ft_printf("P 0.35 %.1f\n", 0.35);
ft_printf("P 0.45 %.1f\n", 0.45);
ft_printf("P 0.55 %.1f\n", 0.55);
ft_printf("P 0.65 %.1f\n", 0.65);
ft_printf("P 0.75 %.1f\n", 0.75);
ft_printf("P 0.85 %.1f\n", 0.85);
ft_printf("P 0.95 %.1f\n", 0.95);
ft_printf("P 0.555 %.2f\n", 0.555); */

/*
printf("%.*f", -3, 3.1415926535);
printf("\n");
ft_printf("%.*f", -3, 3.1415926535);
printf("\n");
printf("\n");



printf("\t test start \n");
printf("'%.0f'", 10.3456);
printf("\n");
ft_printf("'%.0f'", 10.3456);
printf("\n");
printf("\n");

printf("%.1f'",-10.5456);
printf("\n");
ft_printf("%.1f'",-10.5456);
printf("\n");
printf("\n");

printf("'%.2f'", 0.111);
printf("\n");
ft_printf("'%.2f'", 0.111);
printf("\n");
printf("\n");

printf("'%.2f'", 10.3456);
printf("\n");
ft_printf("'%.2f'", 10.3456);
printf("\n");
printf("\n");

printf("'%.1f'", 0.42);
printf("\n");
ft_printf("'%.1f'", 0.42);
printf("\n");
printf("\n");

printf("'%8.2f'", 10.3456);
printf("\n");
ft_printf("'%8.2f'", 10.3456);
printf("\n");
printf("\n");
printf("'%8.4f'", 10.3456);
printf("\n");
ft_printf("'%8.4f'", 10.3456);
printf("\n");
printf("\n");
printf("'%-8.2f'", 10.3456);
printf("\n");
ft_printf("'%-8.2f'", 10.3456);
 */
}


		// printf("|break %c|\n", data->str[data->pos]);

