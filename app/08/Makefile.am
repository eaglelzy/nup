INCLUDES=-I../../include
bin_PROGRAMS=echoserv1 echocli1 echocli2 echoserv2

echoserv1_SOURCES=echoserv.c dg_echo1.c
echoserv1_LDADD=../../libs/libunp.a

echocli1_SOURCES=echocli.c dg_cli1.c
echocli1_LDADD=../../libs/libunp.a

echocli2_SOURCES=echocli.c dg_cli2.c
echocli2_LDADD=../../libs/libunp.a

echoserv2_SOURCES=echoserv2.c str_echo.c sig_chld.c
echoserv2_LDADD=../../libs/libunp.a
