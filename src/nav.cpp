#include "main.h"
using namespace Eigen;
m_point m_tcppoint;
st_tcpdatalist m_sttcpdatalist;
// vector<st_tcpdatalist> v_stdatalist;

// void *pth_udp(void *ip);

// bool SplitBuffer(const char *strBuffer);
// extern MatrixXf m;
// bool biz1(int clientfd, char *buf, int *position);
// void xmltobiz(char *strxmlbuffer, struct st_tcppointcloud *m_tcppointcloud);
struct st_biz
{
	int bizid;
	char xmlbuffer[1001];
};
struct st_tcppointcloud
{
	int type;
} m_tcppointcloud;



CTcpServer TcpServer;
CLogFile logfile;

void EXIT(int sig);

NAV::NAV()
{
	param = &sys.params;
	sys.time = 0;
	sys.err = 0;
	updateParams();
}

NAV *NAV::getInstance()
{
	static NAV instance;
	return &instance;
}

void NAV::updateParams()
{
	float tempf;
	param_get("NAV_THR_R2000_SMP_START", &sys.params.thread_r2000_smp_start);
	//cout<<"  param->NAV_THR_R2000_SMP_START:"<<param->thread_r2000_smp_start<<endl;

	param_get("NAV_THR_R2000_IDE_START", &sys.params.thread_r2000_identify_start);
	//cout<<"  param->NAV_THR_R2000_IDE_START:"<<param->thread_r2000_identify_start<<endl;

	/* for sensor params */
	param_get("R2000_SENS_FRE", &sys.params.r2000_sens_smp_frq);
	//cout<<"  param->R2000_SENS_FRE:"<<param->r2000_sens_smp_frq<<endl;

	param_get("R2000_SENS_SMP_CNT", &sys.params.r2000_sens_smp_cnt);
	//cout<<"  param->R2000_SENS_SMP_CNT:"<<param->r2000_sens_smp_cnt<<endl;

	param_get("R2000_SENS_SMP_CNT_AFTER_FILTER", &sys.params.r2000_sens_smp_cnt_after_filter);
	//cout<<"  param->R2000_SENS_SMP_CNT_AFTER_FILTER "<<sys.params.r2000_sens_smp_cnt_after_filter<<endl;

	sys.params.r2000_sens_angstep = 360.0 / sys.params.r2000_sens_smp_cnt_after_filter; //0.086;//360.0/sys.params.r2000_sens_smp_cnt;
	printf("  param->CACULATE: pm_sens_angstep:%.5f,  cnt:%d \n", param->r2000_sens_angstep, sys.params.r2000_sens_smp_cnt);

	char buf[20];
	param_get("R2000_SENS_IP", &buf);
	sys.params.r2000_sens_ip = buf;
	//cout<<"  param->R2000_SENS_IP:"<<param->r2000_sens_ip<<endl;

	/* for sample params */
	param_get("R2000_SMP_DIST_HLIMIT", &tempf);
	sys.params.r2000_smp_dist_hlimit = tempf;
	//printf("  param->R2000_SMP_DIST_HLIMIT:%.3f\n",param->r2000_smp_dist_hlimit);

	param_get("R2000_SMP_DIST_LLIMIT", &tempf);
	sys.params.r2000_smp_dist_llimit = tempf;
	//printf("  param->R2000_SMP_DIST_LLIMIT:%.3f\n",param->r2000_smp_dist_llimit);

	param_get("R2000_SMP_AMP_HLIMIT", &sys.params.r2000_smp_amp_hlimit);
	//cout<<"  param->R2000_SMP_AMP_HLIMIT:"<<param->r2000_smp_amp_hlimit<<endl;

	param_get("R2000_SMP_AMP_LLIMIT", &sys.params.r2000_smp_amp_llimit);
	//cout<<"  param->R2000_SMP_AMP_LLIMIT:"<<param->r2000_smp_amp_llimit<<endl;

	/* REFBAR paramters */

	param_get("REFBAR_DIAMETER", &tempf);
	sys.params.refbar_diameter = tempf;
	//printf("  param->REFBAR_DIAMETER:%.3f\n",param->refbar_diameter);

	param_get("REFBAR_IDT_MOD_EDIST", &tempf);
	sys.params.refbar_mod_edist = tempf;
	//printf("  param->REFBAR_IDT_MOD_EDIST:%.3f\n",param->refbar_mod_edist);

	param_get("REFBAR_IDT_MOD_MAX_ERRGEN", &tempf);
	sys.params.refbar_mod_max_errgen = tempf;
	//printf("  param->REFBAR_IDT_MOD_MAX_ERRGEN:%.3f\n",param->refbar_mod_max_errgen);

	param_get("REFBAR_IDT_MOD_CONVEX_SCORE", &tempf);
	sys.params.refbar_mod_convex_score = tempf;
	//printf("  param->REFBAR_IDT_MOD_CONVEX_SCORE:%.3f\n",param->refbar_mod_convex_score);

	param_get("REFBAR_IDT_MOD_MAX_AMPERR", &sys.params.refbar_mod_amperr_max);
	//printf("  param->REFBAR_IDT_MOD_MAX_AMPERR:%d\n",param->refbar_mod_amperr_max);

	param_get("REFBAR_IDT_MOD_FILTER6_AMPMAX", &sys.params.refbar_mod_amp_offset_max);
	//printf("  param->REFBAR_IDT_MOD_FILTER6_AMPMAX:%d\n",param->refbar_mod_amp_offset_max);

	sys.params.refbar_mod_min_smp_num = (int)(ceil(atan2(0.5 * sys.params.refbar_diameter, sys.params.r2000_smp_dist_hlimit) * R2A * 2 / sys.params.r2000_sens_angstep)) - 1;
	//printf("  param->CACULATE: pm_refbar_mod_min_smp_num:%d(%.3f)\n",param->refbar_mod_min_smp_num,(atan2(0.5*sys.params.refbar_diameter,sys.params.r2000_smp_dist_hlimit)*R2A*2));

	param_get("REFBAR_IDT_MAXBAR_FORMATCH", &sys.params.refbar_maxbarnum_for_match);
	//printf("  param->REFBAR_IDT_MAXBAR_FORMATCH:%d\n",param->refbar_maxbarnum_for_match);

	param_get("REFBAR_ERR_DIST", &tempf);
	sys.params.refbar_err_dist = tempf;
	//printf("  param->REFBAR_ERR_DIST:%.3f\n",param->refbar_err_dist);

	param_get("LOG_BARMOD", &sys.params.log_barmod);
	//cout<<"  param->LOG_BARMOD:"<<param->log_barmod<<endl;

	param_get("LOG_ERR_MEM_TRI", &sys.params.log_err_mem);
	//cout<<"  param->LOG_ERR_MEM_TRI:"<<param->log_err_mem<<endl;

	param_get("LOG_BAR_LIST", &sys.params.log_barlist);
	//cout<<"  param->LOG_BAR_LIST:"<<param->log_barlist<<endl;
}

int NAV::run()
{

	r2000.ThreadR2000Nav();
	network.ThreadNetwork();
	while(true)
	{
		sleep(1);
	}
	// Tcp_Server.init(starg.port1, false);
	// while (true)
	// {

	// 	//usleep(100000);

	// 	if (Tcp_Server.long_connection == false && Tcp_Server.connected == true)
	// 		Tcp_Server.close_connection();

	// 	int getbuflen = Tcp_Server.rev_data(Tcp_Server.client_addr);

	// 	 if (getbuflen > 0)
	// 	 {
	// 	char ip[20] = {0};

	// 	strcpy(ip, Tcp_Server.GetIP());
	// 	printf("%s is connected!\n", ip);
	// 	if (pthread_create(&pthid, NULL, pth_udp, ip) != 0)
	// 	{
	// 		printf("create thread failed\n");
	// 	}

	// 	//xmltobiz(char *strxmlbuffer, struct st_tcppointcloud *m_tcppointcloud)
	// 	char buf[200000] = {0};
	// 	int buflen = 0;
	// 	biz1(Tcp_Server.connfd, buf, &buflen);
	// 	printf("len=%d\n", buflen);
	// 	char buffer[buflen + 4];
	// 	memset(buffer, 0, sizeof(buffer));
	// 	memcpy(buffer, &buflen, 4);
	// 	memcpy(buffer + 4, buf, buflen);
	// 	Tcp_Server.send_ackdata(buffer, buflen + 4);

	// 		}
	// }

	return 0;
}
