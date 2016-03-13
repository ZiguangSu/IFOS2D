/*------------------------------------------------------------------------
 *   globvar.h - global variables of viscoelastic FD programs
 *
 *  ----------------------------------------------------------------------*/

/* definition of global variables used in the finite difference programs*/
/* generally, for the names of the global variables uppercase letters are used */

/* Add new variables also in exchange_par.c and read_par_json.c */

float XS, YS, DH, TIME, DT, TS, VPPML, PLANE_WAVE_DEPTH, PHI;
float TSNAP1, TSNAP2, TSNAPINC, *FL, TAU, F_REF;
float XREC1, XREC2, YREC1, YREC2;
float REC_ARRAY_DEPTH, REC_ARRAY_DIST;
float REFREC[4]={0.0, 0.0, 0.0, 0.0}, FPML;
int   SEISMO, NDT, NGEOPH, NSRC=1, SEIS_FORMAT, FREE_SURF, READMOD, READREC, SRCREC, FW=0;
int   NX, NY, NT, SOURCE_SHAPE,SOURCE_SHAPE_SH, SOURCE_TYPE, SNAP, SNAP_FORMAT, REC_ARRAY, RUN_MULTIPLE_SHOTS, NTRG;
int   L, BOUNDARY, DC, DRX, NXG, NYG, IDX, IDY, FDORDER, MAXRELERROR;
char  SNAP_FILE[STRING_SIZE], SOURCE_FILE[STRING_SIZE], SIGNAL_FILE[STRING_SIZE], SIGNAL_FILE_SH[STRING_SIZE];
char  MFILE[STRING_SIZE], REC_FILE[STRING_SIZE];
char  LOG_FILE[STRING_SIZE];
char  SEIS_FILE[STRING_SIZE];
FILE *FP;

int VERBOSE;
/* Mpi-variables */
int   NP, NPSP, NPROC, NPROCX, NPROCY, MYID, IENDX, IENDY;
int   POS[3], INDEX[5];     
const int TAG1=1,TAG2=2, TAG3=3, TAG4=4, TAG5=5,TAG6=6; 

/* spatial adaptive Code variables*/
int   check_id, cfgt_id, cfgt, jumpid;
float DH1;

/* TDFWI Code IFOS_elastic*/
char JACOBIAN[STRING_SIZE], DATA_DIR[STRING_SIZE], FREQ_FILE[STRING_SIZE];

int USE_WORKFLOW;
char FILE_WORKFLOW[STRING_SIZE];
int WORKFLOW_STAGE;

int TAPER, TAPERLENGTH, INVTYPE;
int GRADT1,GRADT2,GRADT3,GRADT4;
int ITERMAX, REC1, REC2, PARAMETERIZATION, FORWARD_ONLY, ADJOINT_TYPE;
int  GRAD_METHOD;
float TSHIFT_back;
int MODEL_FILTER, FILT_SIZE;
float EPSILON, MUN, EPSILON_u, EPSILON_rho;

int TESTSHOT_START, TESTSHOT_END, TESTSHOT_INCR, NO_OF_TESTSHOTS; 
int SWS_TAPER_GRAD_VERT, SWS_TAPER_GRAD_HOR, SWS_TAPER_GRAD_SOURCES, SWS_TAPER_CIRCULAR_PER_SHOT, SRTSHAPE, FILTSIZE;
int SWS_TAPER_FILE, SWS_TAPER_FILE_PER_SHOT;
float SRTRADIUS;
char TAPER_FILE_NAME[STRING_SIZE];

int SPATFILTER, SPAT_FILT_SIZE, SPAT_FILT_1, SPAT_FILT_ITER;

int INV_RHO_ITER, INV_VS_ITER, INV_VP_ITER;

int MIN_ITER;

char INV_MODELFILE[STRING_SIZE];
int nfstart, nf;

int nfstart_jac, nf_jac;

float VPUPPERLIM, VPLOWERLIM, VSUPPERLIM, VSLOWERLIM, RHOUPPERLIM, RHOLOWERLIM;

float npower, k_max_PML;

int TAPER_STF;
int INV_STF, N_STF, N_STF_START,TW_IND;
char PARA[STRING_SIZE];

int TIME_FILT, ORDER, ZERO_PHASE;
int WRITE_FILTERED_DATA;
float F_LOW_PASS_START, F_LOW_PASS_END, F_LOW_PASS_INCR, F_HIGH_PASS;

int LNORM, DTINV;

int STEPMAX;
float EPS_SCALE, SCALEFAC;

float PRO;

int EPRECOND;
float EPSILON_WE,EPSILON_WE_SH;
int EPRECOND_ITER;
int EPRECOND_PER_SHOT;
int EPRECOND_PER_SHOT_SH;

int N_LBFGS;
int LBFGS_STEP_LENGTH;

float LBFGS_SCALE_GRADIENTS;
int WOLFE_CONDITION=0;
int WOLFE_NUM_TEST=5;
int WOLFE_TRY_OLD_STEPLENGTH=1;
float WOLFE_C1_SL;
float WOLFE_C2_SL;

/* trace kill variables */
int TRKILL;
char TRKILL_FILE[STRING_SIZE];

int TRKILL_OFFSET;
int TRKILL_STF_OFFSET_INVERT;
float TRKILL_OFFSET_LOWER;
float TRKILL_OFFSET_UPPER;

/* trace kill STF variables */
int TRKILL_STF;
char TRKILL_FILE_STF[STRING_SIZE];

int TRKILL_STF_OFFSET;
float TRKILL_STF_OFFSET_LOWER;
float TRKILL_STF_OFFSET_UPPER;

int TIMEWIN, NORMALIZE;
float TWLENGTH_PLUS, TWLENGTH_MINUS, GAMMA;
char PICKS_FILE[STRING_SIZE];
char MISFIT_LOG_FILE[STRING_SIZE]; 

int GRAD_FILTER, FILT_SIZE_GRAD;

int VELOCITY;

float WATERLEVEL_LNORM8;

float VP_VS_RATIO;

int S;

float S_VP, S_VS, S_RHO;

int GRAD_FILT_WAVELENGTH;
float A;

int ACOUSTIC;

int VERBOSE;

int WAVETYPE;
int JOINT_INVERSION_PSV_SH_TYPE;

float JOINT_INVERSION_PSV_SH_ALPHA_VS;
float JOINT_INVERSION_PSV_SH_ALPHA_RHO;
int SNAPSHOT_START,SNAPSHOT_END,SNAPSHOT_INCR;