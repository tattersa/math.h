#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_
#include <stdio.h>

#define S21_PI 3.1415926535897932384626433832795028841971693993751058209749445923
#define S21_PI_2 1.5707963267948966192313216916397514420985846996875529104874722961
#define S21_LN_2 0.6931471805599453094172321214581765680755001343602552541206800094
#define S21_E 2.7182818284590452353602874713526624977572470936999595749669676277

#define EPS 1e-6



// sets the value to INF
#define S21_INF (__builtin_inff())
// sets the value to NAN
#define S21_NAN (__builtin_nanf(""))
// returns non zero if not NAN or +-INF
#define is_finite(x) __builtin_isfinite(x)
// check if NAN
#define is_nan(x) __builtin_isnan(x)
// check for INF
#define is_inf(x) __builtin_isinf(x)
#define is_normal(x) __builtin_isnormal(x)




/* #define S21_HUGE_VAL (__builtin_inff()) */
/* #define is_inf(x) __builtin_isinf_sign(x) */


static const double trig_angles[] =  {
0.00000000000000000000, 0.00785398163397448348, 0.01570796326794896697, 0.02356194490192345045,
0.03141592653589793394, 0.03926990816987241395, 0.04712388980384689396, 0.05497787143782137398,
0.06283185307179585399, 0.07068583470577033401, 0.07853981633974481402, 0.08639379797371929404,
0.09424777960769377405, 0.10210176124166825407, 0.10995574287564273408, 0.11780972450961721409,
0.12566370614359170799, 0.13351768777756620188, 0.14137166941154069577, 0.14922565104551518966,
0.15707963267948968356, 0.16493361431346417745, 0.17278759594743867134, 0.18064157758141316523,
0.18849555921538765912, 0.19634954084936215302, 0.20420352248333664691, 0.21205750411731114080,
0.21991148575128563469, 0.22776546738526012859, 0.23561944901923462248, 0.24347343065320911637,
0.25132741228718358251, 0.25918139392115807640, 0.26703537555513257029, 0.27488935718910706418,
0.28274333882308155808, 0.29059732045705605197, 0.29845130209103054586, 0.30630528372500503975,
0.31415926535897953364, 0.32201324699295402754, 0.32986722862692852143, 0.33772121026090301532,
0.34557519189487750921, 0.35342917352885200311, 0.36128315516282649700, 0.36913713679680099089,
0.37699111843077548478, 0.38484510006474997867, 0.39269908169872447257, 0.40055306333269896646,
0.40840704496667346035, 0.41626102660064795424, 0.42411500823462244814, 0.43196898986859694203,
0.43982297150257143592, 0.44767695313654592981, 0.45553093477052042370, 0.46338491640449491760,
0.47123889803846941149, 0.47909287967244390538, 0.48694686130641839927, 0.49480084294039289317,
0.50265482457436738706, 0.51050880620834182544, 0.51836278784231626382, 0.52621676947629070220,
0.53407075111026514058, 0.54192473274423957896, 0.54977871437821401734, 0.55763269601218845573,
0.56548667764616289411, 0.57334065928013733249, 0.58119464091411177087, 0.58904862254808620925,
0.59690260418206064763, 0.60475658581603508601, 0.61261056745000952439, 0.62046454908398396277,
0.62831853071795840115, 0.63617251235193283954, 0.64402649398590727792, 0.65188047561988171630,
0.65973445725385615468, 0.66758843888783059306, 0.67544242052180503144, 0.68329640215577946982,
0.69115038378975390820, 0.69900436542372834658, 0.70685834705770278497, 0.71471232869167722335,
0.72256631032565166173, 0.73042029195962610011, 0.73827427359360053849, 0.74612825522757497687,
0.75398223686154941525, 0.76183621849552385363, 0.76969020012949829201, 0.77754418176347273040,
0.78539816339744716878, 0.79325214503142160716, 0.80110612666539604554, 0.80896010829937048392,
0.81681408993334492230, 0.82466807156731936068, 0.83252205320129379906, 0.84037603483526823744,
0.84823001646924267583, 0.85608399810321711421, 0.86393797973719155259, 0.87179196137116599097,
0.87964594300514042935, 0.88749992463911486773, 0.89535390627308930611, 0.90320788790706374449,
0.91106186954103818287, 0.91891585117501262125, 0.92676983280898705964, 0.93462381444296149802,
0.94247779607693593640, 0.95033177771091037478, 0.95818575934488481316, 0.96603974097885925154,
0.97389372261283368992, 0.98174770424680812830, 0.98960168588078256668, 0.99745566751475700507,
1.00530964914873144345, 1.01316363078270588183, 1.02101761241668032021, 1.02887159405065475859,
1.03672557568462919697, 1.04457955731860363535, 1.05243353895257807373, 1.06028752058655251211,
1.06814150222052695050, 1.07599548385450138888, 1.08384946548847582726, 1.09170344712245026564,
1.09955742875642470402, 1.10741141039039914240, 1.11526539202437358078, 1.12311937365834801916,
1.13097335529232245754, 1.13882733692629689592, 1.14668131856027133431, 1.15453530019424577269,
1.16238928182822021107, 1.17024326346219464945, 1.17809724509616908783, 1.18595122673014352621,
1.19380520836411796459, 1.20165918999809240297, 1.20951317163206684135, 1.21736715326604127974,
1.22522113490001571812, 1.23307511653399015650, 1.24092909816796459488, 1.24878307980193903326,
1.25663706143591347164, 1.26449104306988791002, 1.27234502470386234840, 1.28019900633783678678,
1.28805298797181122517, 1.29590696960578566355, 1.30376095123976010193, 1.31161493287373454031,
1.31946891450770897869, 1.32732289614168341707, 1.33517687777565785545, 1.34303085940963229383,
1.35088484104360673221, 1.35873882267758117059, 1.36659280431155560898, 1.37444678594553004736,
1.38230076757950448574, 1.39015474921347892412, 1.39800873084745336250, 1.40586271248142780088,
1.41371669411540223926, 1.42157067574937667764, 1.42942465738335111602, 1.43727863901732555441,
1.44513262065129999279, 1.45298660228527443117, 1.46084058391924886955, 1.46869456555322330793,
1.47654854718719774631, 1.48440252882117218469, 1.49225651045514662307, 1.50011049208912106145,
1.50796447372309549984, 1.51581845535706993822, 1.52367243699104437660, 1.53152641862501881498,
1.53938040025899325336, 1.54723438189296769174, 1.55508836352694213012, 1.56294234516091656850};



static const double sin_for_trig_angles[] = {
0.00000000000000000000, 0.00785390088871133429, 0.01570731731182067653, 0.02355976483361015501,
0.03141075907812829539, 0.03925981575906860749, 0.04710645070964265630, 0.05495017991244573968,
0.06279051952931336532, 0.07062698593116666777, 0.07845909572784492815, 0.08628636579792335619,
0.09410831331851429547, 0.10192445579505001341, 0.10973431109104523894, 0.11753739745783761198,
0.12533323356430422399, 0.13312133852655234751, 0.14090123193758266120, 0.14867243389692300273,
0.15643446504023089037, 0.16418684656886297369, 0.17192910027940958919, 0.17966074859319259918,
0.18738131458572469422, 0.19509032201612834200, 0.20278729535651256805, 0.21047175982130575584,
0.21814324139654265743, 0.22580126686910380751, 0.23344536385590553778, 0.24107506083303879057,
0.24868988716485490779, 0.25628937313299676222, 0.26387304996537303684, 0.27144044986507440332,
0.27899110603922941184, 0.28652455272779847438, 0.29404032523230413766, 0.30153795994449587436,
0.30901699437494762362, 0.31647696718158631758, 0.32391741819814963332, 0.33133788846257121566,
0.33873792024529161924, 0.34611705707749322394, 0.35347484377925738157, 0.36081082648764205745,
0.36812455268467823453, 0.37541557122528335322, 0.38268343236509006530, 0.38992768778818858480,
0.39714789063478092519, 0.40434359552874531664, 0.41151435860510910303, 0.41865973753742842428,
0.42577929156507299499, 0.43287258152041429630, 0.43993916985591550374, 0.44697862067112148057,
0.45399049973954717089, 0.46097437453546273475, 0.46792981426057377256, 0.47485638987059499306,
0.48175367410171568590, 0.48862124149695531752, 0.49545866843240786768, 0.50226553314337280112,
0.50904141575037154991, 0.51578589828504765760, 0.52249856471594903603, 0.52917900097419074513,
0.53582679497899671217, 0.54244153666311881499, 0.54902281799813176170, 0.55557023301960220568,
0.56208337785213054411, 0.56856185073426385537, 0.57500525204327843738, 0.58141318431983042005,
0.58778525229247292970, 0.59412106290203829358, 0.60042022532588378112, 0.60668235100199938511,
0.61290705365297615725, 0.61909394930983361775, 0.62524265633570477111, 0.63135279544937726549,
0.63742398974868924458, 0.64345586473377844826, 0.64944804833018312824, 0.65540017091179335334,
0.66131186532365128912, 0.66718276690459904531, 0.67301251350977269334, 0.67880074553294106782,
0.68454710592868797247, 0.69025124023443642341, 0.69591279659231357042, 0.70153142577085494816,
0.70710678118654671768, 0.71263851892520457029, 0.71812629776318797421, 0.72356977918844845639,
0.72896862742141061976, 0.73432250943568460949, 0.73963109497860874910, 0.74489405659162108057,
0.75011106963045855048, 0.75528181228518259790, 0.76040596560002990688, 0.76548321349308710030,
0.77051324277578816158, 0.77549574317223338025, 0.78043040733832863114, 0.78531693088074380592,
0.79015501237568922741, 0.79494435338750888873, 0.79968465848708937045, 0.80437563527008329971,
0.80901699437494622790, 0.81360844950078581365, 0.81814971742502221047, 0.82264051802085856965,
0.82708057427456058044, 0.83146961230254398223, 0.83580736136826899382, 0.84009355389894061898,
0.84432792550201379638, 0.84851021498150237734, 0.85264016435409092454, 0.85671751886504833823,
0.86074202700394232806, 0.86471344052015376101, 0.86863151443818992930, 0.87249600707279579236,
0.87630668004386226219, 0.88006329829113061103, 0.88376563008869209539, 0.88741344705928190190,
0.89100652418836653244, 0.89454463983802376062, 0.89802757576061430282, 0.90145511711224436067,
0.90482705246601820428, 0.90814317382507997922, 0.91140327663544393232, 0.91460715979861226493,
0.91775462568397983565, 0.92084548014102494701, 0.92387953251128546395, 0.92685659564011952619,
0.92977648588825012772, 0.93263902314309285284, 0.93544403082986606843, 0.93819133592248288837,
0.94088076895422423769, 0.94351216402819235781, 0.94608535882754410894, 0.94860019462550343732,
0.95105651629515239049, 0.95345417231900007649, 0.95579301479832897602, 0.95807289946231803234,
0.96029368567694195507, 0.96245523645364618903, 0.96455741845779701386, 0.96660010201690625226,
0.96858316112863007962, 0.97050647346854144239, 0.97236992039767560479, 0.97417338696984835916,
0.97591676193874644777, 0.97759993776478975967, 0.97922281062176487850, 0.98078528040322957232,
0.98228725072868783053, 0.98372862894953506702, 0.98510932615477312226, 0.98642925717649471260,
0.98768834059513698810, 0.98888649874450387447, 0.99002365771655688985, 0.99109974736597414112,
0.99211470131447721731, 0.99306845695492571480, 0.99396095545517914059, 0.99479214176172595568,
0.99556196460307953524, 0.99627037649294083516, 0.99691733373312757093, 0.99750279641626972714,
0.99802672842827123203, 0.99848909745053764526, 0.99888987496196972088, 0.99922903624072272315,
0.99950656036573138632, 0.99972243021800042447, 0.99987663248166051187, 0.99996915764478966847};
static const double cos_for_trig_angles[] = {
1.00000000000000000000, 0.99996915764478971222, 0.99987663248166059861, 0.99972243021800055355,
0.99950656036573155697, 0.99922903624072293479, 0.99888987496196997285, 0.99848909745053793686,
0.99802672842827156265, 0.99750279641627009604, 0.99691733373312797751, 0.99627037649294127871,
0.99556196460308001505, 0.99479214176172647111, 0.99396095545517969098, 0.99306845695492629945,
0.99211470131447783373, 0.99109974736597478850, 0.99002365771655756726, 0.98888649874450458094,
0.98768834059513772281, 0.98642925717649547457, 0.98510932615477391058, 0.98372862894953588082,
0.98228725072868866894, 0.98078528040323043437, 0.97922281062176576332, 0.97759993776479066639,
0.97591676193874737542, 0.97417338696984930681, 0.97236992039767657157, 0.97050647346854242734,
0.96858316112863108879, 0.96660010201690727807, 0.96455741845779805540, 0.96245523645364724531,
0.96029368567694302529, 0.95807289946231911557, 0.95579301479833007129, 0.95345417231900118297,
0.95105651629515350728, 0.94860019462550456348, 0.94608535882754524356, 0.94351216402819350007,
0.94088076895422538662, 0.93819133592248404315, 0.93544403082986722815, 0.93263902314309401657,
0.92977648588825129465, 0.92685659564012069534, 0.92387953251128663451, 0.92084548014102611806,
0.91775462568398100637, 0.91460715979861343441, 0.91140327663544509968, 0.90814317382508114360,
0.90482705246601936486, 0.90145511711224551654, 0.89802757576061545316, 0.89454463983802490451,
0.89100652418836766907, 0.88741344705928303045, 0.88376563008869321499, 0.88006329829113172082,
0.87630668004386336141, 0.87249600707279690724, 0.86863151443819105975, 0.86471344052015490701,
0.86074202700394348951, 0.85671751886504951513, 0.85264016435409211673, 0.84851021498150358476,
0.84432792550201501899, 0.84009355389894185666, 0.83580736136827024651, 0.83146961230254524982,
0.82708057427456186295, 0.82264051802085986695, 0.81814971742502352246, 0.81360844950078714023,
0.80901699437494756901, 0.80437563527008465529, 0.79968465848709074039, 0.79494435338751027299,
0.79015501237569062587, 0.78531693088074521852, 0.78043040733833005774, 0.77549574317223482077,
0.77051324277578961598, 0.76548321349308856847, 0.76040596560003138871, 0.75528181228518409334,
0.75011106963046005942, 0.74489405659162260284, 0.73963109497861028471, 0.73432250943568615827,
0.72896862742141218166, 0.72356977918845003130, 0.71812629776318956208, 0.71263851892520617095,
0.70710678118654833108, 0.70153142577085657420, 0.69591279659231520898, 0.69025124023443807438,
0.68454710592868963574, 0.67880074553294274329, 0.67301251350977438096, 0.66718276690460074491,
0.66131186532365300064, 0.65540017091179507663, 0.64944804833018486323, 0.64345586473378019486,
0.63742398974869100267, 0.63135279544937903491, 0.62524265633570655181, 0.61909394930983540961,
0.61290705365297796012, 0.60668235100200119893, 0.60042022532588560572, 0.59412106290204012892,
0.58778525229247477566, 0.58141318431983227648, 0.57500525204328030410, 0.56856185073426573234,
0.56208337785213243127, 0.55557023301960410281, 0.54902281799813366876, 0.54244153666312073180,
0.53582679497899863864, 0.52917900097419268114, 0.52249856471595098147, 0.51578589828504961236,
0.50904141575037351389, 0.50226553314337477410, 0.49545866843240984962, 0.48862124149695730828,
0.48175367410171768533, 0.47485638987059704993, 0.46792981426057588714, 0.46097437453546490733,
0.45399049973954940171, 0.44697862067112376991, 0.43993916985591785188, 0.43287258152041670339,
0.42577929156507546133, 0.41865973753743095006, 0.41151435860511168847, 0.40434359552874796196,
0.39714789063478363057, 0.38992768778819135038, 0.38268343236509289130, 0.37541557122528623977,
0.36812455268468118177, 0.36081082648764506557, 0.35347484377926045065, 0.34611705707749635411,
0.33873792024529481061, 0.33133788846257446832, 0.32391741819815294737, 0.31647696718158969311,
0.30901699437495106071, 0.30153795994449937302, 0.29404032523230769797, 0.28652455272780209635,
0.27899110603923309553, 0.27144044986507814870, 0.26387304996537684396, 0.25628937313300063106,
0.24868988716485883833, 0.24107506083304275586, 0.23344536385590956466, 0.22580126686910789594,
0.21814324139654680734, 0.21047175982130996718, 0.20278729535651684074, 0.19509032201613267595,
0.18738131458572908933, 0.17966074859319705534, 0.17192910027941410630, 0.16418684656886755161,
0.15643446504023552897, 0.14867243389692770185, 0.14090123193758742068, 0.13312133852655716717,
0.12533323356430910366, 0.11753739745784255147, 0.10973431109105022425, 0.10192445579505504431,
0.09410831331851937171, 0.08628636579792847752, 0.07845909572785009431, 0.07062698593117187850,
0.06279051952931862034, 0.05495017991245103870, 0.04710645070964799903, 0.03925981575907399364,
0.03141075907813372465, 0.02355976483361563053, 0.01570731731182619799, 0.00785390088871690137};


static const long double CORDIC_tan_angles[] = {
0.785398163397448278999490867136, 0.392699081698724139499745433568, 0.196349540849362069749872716784,
0.098174770424681034874936358392, 0.049087385212340517437468179196, 0.024543692606170258718734089598,
0.012271846303085129359367044799, 0.006135923151542564679683522400, 0.003067961575771282339841761200,
0.001533980787885641169920880600, 0.000766990393942820584960440300, 0.000383495196971410292480220150,
0.000191747598485705146240110075, 0.000095873799242852573120055037, 0.000047936899621426286560027519,
0.000023968449810713143280013759, 0.000011984224905356571640006880, 0.000005992112452678285820003440,
0.000002996056226339142910001720, 0.000001498028113169571455000860, 0.000000749014056584785727500430,
0.000000374507028292392863750215, 0.000000187253514146196431875107, 0.000000093626757073098215937554,
0.000000046813378536549107968777, 0.000000023406689268274553984388, 0.000000011703344634137276992194,
0.000000005851672317068638496097, 0.000000002925836158534319248049, 0.000000001462918079267159624024,
0.000000000731459039633579812012, 0.000000000365729519816789906006, 0.000000000182864759908394953003,
0.000000000091432379954197476502, 0.000000000045716189977098738251, 0.000000000022858094988549369125,
0.000000000011429047494274684563, 0.000000000005714523747137342281, 0.000000000002857261873568671141,
0.000000000001428630936784335570, 0.000000000000714315468392167785, 0.000000000000357157734196083893,
0.000000000000178578867098041946, 0.000000000000089289433549020973, 0.000000000000044644716774510487,
0.000000000000022322358387255243, 0.000000000000011161179193627622, 0.000000000000005580589596813811,
0.000000000000002790294798406905, 0.000000000000001395147399203453, 0.000000000000000697573699601726,
0.000000000000000348786849800863, 0.000000000000000174393424900432, 0.000000000000000087196712450216,
0.000000000000000043598356225108, 0.000000000000000021799178112554, 0.000000000000000010899589056277,
0.000000000000000005449794528138, 0.000000000000000002724897264069, 0.000000000000000001362448632035,
0.000000000000000000681224316017, 0.000000000000000000340612158009, 0.000000000000000000170306079004,
0.000000000000000000085153039502, 0.000000000000000000042576519751, 0.000000000000000000021288259876,
0.000000000000000000010644129938, 0.000000000000000000005322064969, 0.000000000000000000002661032484,
0.000000000000000000001330516242, 0.000000000000000000000665258121, 0.000000000000000000000332629061,
0.000000000000000000000166314530, 0.000000000000000000000083157265, 0.000000000000000000000041578633,
0.000000000000000000000020789316, 0.000000000000000000000010394658, 0.000000000000000000000005197329,
0.000000000000000000000002598665, 0.000000000000000000000001299332, 0.000000000000000000000000649666,
0.000000000000000000000000324833, 0.000000000000000000000000162417, 0.000000000000000000000000081208,
0.000000000000000000000000040604, 0.000000000000000000000000020302, 0.000000000000000000000000010151,
0.000000000000000000000000005076, 0.000000000000000000000000002538, 0.000000000000000000000000001269,
0.000000000000000000000000000634, 0.000000000000000000000000000317, 0.000000000000000000000000000159,
0.000000000000000000000000000079, 0.000000000000000000000000000040, 0.000000000000000000000000000020,
0.000000000000000000000000000010, 0.000000000000000000000000000005, 0.000000000000000000000000000002,
0.000000000000000000000000000001, 0.000000000000000000000000000001};

static const long double CORDIC_tan_values[] = {
0.999999999999999938742577254569, 0.414213562373095030874452227021, 0.198912367379657998957341417945,
0.098491403357164249210474547130, 0.049126849769467252188162630436, 0.024548622108925443146523921734,
0.012272462379566274752190223243, 0.006136000157623401725153297224, 0.003067971201422664867399338947,
0.001533981991088666468739746802, 0.000766990544343092575266575826, 0.000383495215771440973400728026,
0.000191747600835708877673046860, 0.000095873799536603036308278496, 0.000047936899658145094357639416,
0.000023968449815302994251820114, 0.000011984224905930303011069084, 0.000005992112452750002241386215,
0.000002996056226348107462726266, 0.000001498028113170692024065579, 0.000000749014056584925798646445,
0.000000374507028292410372630542, 0.000000187253514146198620491611, 0.000000093626757073098489514617,
0.000000046813378536549142164294, 0.000000023406689268274558259232, 0.000000011703344634137277526146,
0.000000005851672317068638562740, 0.000000002925836158534319256328, 0.000000001462918079267159625034,
0.000000000731459039633579812164, 0.000000000365729519816789906031, 0.000000000182864759908394953003,
0.000000000091432379954197476502, 0.000000000045716189977098738251, 0.000000000022858094988549369125,
0.000000000011429047494274684563, 0.000000000005714523747137342281, 0.000000000002857261873568671141,
0.000000000001428630936784335570, 0.000000000000714315468392167785, 0.000000000000357157734196083893,
0.000000000000178578867098041946, 0.000000000000089289433549020973, 0.000000000000044644716774510487,
0.000000000000022322358387255243, 0.000000000000011161179193627622, 0.000000000000005580589596813811,
0.000000000000002790294798406905, 0.000000000000001395147399203453, 0.000000000000000697573699601726,
0.000000000000000348786849800863, 0.000000000000000174393424900432, 0.000000000000000087196712450216,
0.000000000000000043598356225108, 0.000000000000000021799178112554, 0.000000000000000010899589056277,
0.000000000000000005449794528138, 0.000000000000000002724897264069, 0.000000000000000001362448632035,
0.000000000000000000681224316017, 0.000000000000000000340612158009, 0.000000000000000000170306079004,
0.000000000000000000085153039502, 0.000000000000000000042576519751, 0.000000000000000000021288259876,
0.000000000000000000010644129938, 0.000000000000000000005322064969, 0.000000000000000000002661032484,
0.000000000000000000001330516242, 0.000000000000000000000665258121, 0.000000000000000000000332629061,
0.000000000000000000000166314530, 0.000000000000000000000083157265, 0.000000000000000000000041578633,
0.000000000000000000000020789316, 0.000000000000000000000010394658, 0.000000000000000000000005197329,
0.000000000000000000000002598665, 0.000000000000000000000001299332, 0.000000000000000000000000649666,
0.000000000000000000000000324833, 0.000000000000000000000000162417, 0.000000000000000000000000081208,
0.000000000000000000000000040604, 0.000000000000000000000000020302, 0.000000000000000000000000010151,
0.000000000000000000000000005076, 0.000000000000000000000000002538, 0.000000000000000000000000001269,
0.000000000000000000000000000634, 0.000000000000000000000000000317, 0.000000000000000000000000000159,
0.000000000000000000000000000079, 0.000000000000000000000000000040, 0.000000000000000000000000000020,
0.000000000000000000000000000010, 0.000000000000000000000000000005, 0.000000000000000000000000000002,
0.000000000000000000000000000001, 0.000000000000000000000000000001};


static const double exp_arguments[] = {
-0.693147180559945, -0.686215708754346, -0.679284236948746,
-0.672352765143147, -0.665421293337547, -0.658489821531948,
-0.651558349726349, -0.644626877920749, -0.637695406115150,
-0.630763934309550, -0.623832462503951, -0.616900990698351,
-0.609969518892752, -0.603038047087152, -0.596106575281553,
-0.589175103475953, -0.582243631670354, -0.575312159864755,
-0.568380688059155, -0.561449216253556, -0.554517744447956,
-0.547586272642357, -0.540654800836757, -0.533723329031158,
-0.526791857225558, -0.519860385419959, -0.512928913614360,
-0.505997441808760, -0.499065970003161, -0.492134498197561,
-0.485203026391962, -0.478271554586362, -0.471340082780763,
-0.464408610975163, -0.457477139169564, -0.450545667363964,
-0.443614195558365, -0.436682723752766, -0.429751251947166,
-0.422819780141567, -0.415888308335967, -0.408956836530368,
-0.402025364724768, -0.395093892919169, -0.388162421113569,
-0.381230949307970, -0.374299477502370, -0.367368005696771,
-0.360436533891172, -0.353505062085572, -0.346573590279973,
-0.339642118474373, -0.332710646668774, -0.325779174863174,
-0.318847703057575, -0.311916231251975, -0.304984759446376,
-0.298053287640776, -0.291121815835177, -0.284190344029578,
-0.277258872223978, -0.270327400418379, -0.263395928612779,
-0.256464456807180, -0.249532985001580, -0.242601513195981,
-0.235670041390381, -0.228738569584782, -0.221807097779182,
-0.214875625973583, -0.207944154167984, -0.201012682362384,
-0.194081210556785, -0.187149738751185, -0.180218266945586,
-0.173286795139986, -0.166355323334387, -0.159423851528787,
-0.152492379723188, -0.145560907917588, -0.138629436111989,
-0.131697964306390, -0.124766492500790, -0.117835020695191,
-0.110903548889591, -0.103972077083992, -0.097040605278392,
-0.090109133472793, -0.083177661667193, -0.076246189861594,
-0.069314718055994, -0.062383246250395, -0.055451774444796,
-0.048520302639196, -0.041588830833597, -0.034657359027997,
-0.027725887222398, -0.020794415416798, -0.013862943611199,
-0.006931471805599, 0.000000000000000, 0.006931471805599,
0.013862943611199, 0.020794415416798, 0.027725887222398,
0.034657359027997, 0.041588830833597, 0.048520302639196,
0.055451774444796, 0.062383246250395, 0.069314718055995,
0.076246189861594, 0.083177661667193, 0.090109133472793,
0.097040605278392, 0.103972077083992, 0.110903548889591,
0.117835020695191, 0.124766492500790, 0.131697964306390,
0.138629436111989, 0.145560907917589, 0.152492379723188,
0.159423851528787, 0.166355323334387, 0.173286795139986,
0.180218266945586, 0.187149738751185, 0.194081210556785,
0.201012682362384, 0.207944154167984, 0.214875625973583,
0.221807097779183, 0.228738569584782, 0.235670041390381,
0.242601513195981, 0.249532985001580, 0.256464456807180,
0.263395928612779, 0.270327400418379, 0.277258872223978,
0.284190344029578, 0.291121815835177, 0.298053287640777,
0.304984759446376, 0.311916231251975, 0.318847703057575,
0.325779174863174, 0.332710646668774, 0.339642118474373,
0.346573590279973, 0.353505062085572, 0.360436533891172,
0.367368005696771, 0.374299477502371, 0.381230949307970,
0.388162421113569, 0.395093892919169, 0.402025364724768,
0.408956836530368, 0.415888308335967, 0.422819780141567,
0.429751251947166, 0.436682723752766, 0.443614195558365,
0.450545667363965, 0.457477139169564, 0.464408610975163,
0.471340082780763, 0.478271554586362, 0.485203026391962,
0.492134498197561, 0.499065970003161, 0.505997441808760,
0.512928913614360, 0.519860385419959, 0.526791857225558,
0.533723329031158, 0.540654800836757, 0.547586272642357,
0.554517744447956, 0.561449216253556, 0.568380688059155,
0.575312159864755, 0.582243631670354, 0.589175103475954,
0.596106575281553, 0.603038047087152, 0.609969518892752,
0.616900990698351, 0.623832462503951, 0.630763934309550,
0.637695406115150, 0.644626877920749, 0.651558349726349,
0.658489821531948, 0.665421293337548, 0.672352765143147,
0.679284236948746, 0.686215708754346, 0.693147180559945};
static const double exp_values[] = {
0.500000000000000, 0.503477775028359, 0.506979739895015,
0.510506062853597, 0.514056913328033, 0.517632461920689,
0.521232880420561, 0.524858341811534, 0.528509020280690,
0.532185091226680, 0.535886731268147, 0.539614118252214,
0.543367431263029, 0.547146850630370, 0.550952557938305,
0.554784736033923, 0.558643569036110, 0.562529242344405,
0.566441942647899, 0.570381857934212, 0.574349177498518,
0.578344091952644, 0.582366793234228, 0.586417474615939,
0.590496330714765, 0.594603557501361, 0.598739352309464,
0.602903913845380, 0.607097442197523, 0.611320138846034,
0.615572206672458, 0.619853849969493, 0.624165274450806,
0.628506687260914, 0.632878296985140, 0.637280313659631,
0.641712948781452, 0.646176415318746, 0.650670927720967,
0.655196701929182, 0.659753955386447, 0.664342907048256,
0.668963777393056, 0.673616788432845, 0.678302163723836,
0.683020128377198, 0.687770909069872, 0.692554734055462,
0.697371833175203, 0.702222437868999, 0.707106781186548,
0.712025097798536, 0.716977624007914, 0.721964597761248,
0.726986258660155, 0.732042847972813, 0.737134608645551,
0.742261785314525, 0.747424624317469, 0.752623373705534,
0.757858283255199, 0.763129604480280, 0.768437590644006,
0.773782496771195, 0.779164579660500, 0.784584097896751,
0.790041311863377, 0.795536483754919, 0.801069877589622,
0.806641759222126, 0.812252396356236, 0.817902058557781,
0.823591017267573, 0.829319545814442, 0.835087919428369,
0.840896415253715, 0.846745312362527, 0.852634891767957,
0.858565436437754, 0.864537231307865, 0.870550563296124,
0.876605721316035, 0.882702996290655, 0.888842681166570,
0.895025070927972, 0.901250462610830, 0.907519155317161,
0.913831450229401, 0.920187650624875, 0.926588061890371,
0.933032991536807, 0.939522749214012, 0.946057646725596,
0.952637998043937, 0.959264119325264, 0.965936328924846,
0.972654947412286, 0.979420297586927, 0.986232704493359,
0.993092495437036, 1.000000000000000, 1.006955550056719,
1.013959479790029, 1.021012125707193, 1.028113826656067,
1.035264923841378, 1.042465760841121, 1.049716683623067,
1.057018040561380, 1.064370182453360, 1.071773462536293,
1.079228236504427, 1.086734862526058, 1.094293701260740,
1.101905115876611, 1.109569472067845, 1.117287138072220,
1.125058484688809, 1.132883885295799, 1.140763715868424,
1.148698354997035, 1.156688183905287, 1.164733586468456,
1.172834949231879, 1.180992661429530, 1.189207115002721,
1.197478704618929, 1.205807827690760, 1.214194884395047,
1.222640277692069, 1.231144413344916, 1.239707699938987,
1.248330548901612, 1.257013374521828, 1.265756593970280,
1.274560627319262, 1.283425897562904, 1.292352830637492,
1.301341855441934, 1.310393403858363, 1.319507910772894,
1.328685814096512, 1.337927554786112, 1.347233576865690,
1.356604327447672, 1.366040256754396, 1.375541818139744,
1.385109468110925, 1.394743666350405, 1.404444875737997,
1.414213562373095, 1.424050195597072, 1.433955248015827,
1.443929195522496, 1.453972517320311, 1.464085695945625,
1.474269217291101, 1.484523570629049, 1.494849248634938,
1.505246747411067, 1.515716566510398, 1.526259208960559,
1.536875181288012, 1.547564993542390, 1.558329159321000,
1.569168195793502, 1.580082623726754, 1.591072967509837,
1.602139755179244, 1.613283518444253, 1.624504792712471,
1.635804117115562, 1.647182034535146, 1.658639091628883,
1.670175838856739, 1.681792830507429, 1.693490624725054,
1.705269783535914, 1.717130872875508, 1.729074462615730,
1.741101126592248, 1.753211442632070, 1.765405992581310,
1.777685362333140, 1.790050141855945, 1.802500925221661,
1.815038310634322, 1.827662900458801, 1.840375301249750,
1.853176123780742, 1.866065983073615, 1.879045498428024,
1.892115293451192, 1.905275996087875, 1.918528238650529,
1.931872657849691, 1.945309894824571, 1.958840595173854,
1.972465408986718, 1.986184990874072, 2.000000000000000};

static const double ln_arguments[] = {
0.100000, 0.200000, 0.300000,
0.400000, 0.500000, 0.600000, 0.700000,
0.800000, 0.900000, 1.000000, 1.100000,
1.200000, 1.300000, 1.400000, 1.500000,
1.600000, 1.700000, 1.800000, 1.900000};

static const double ln_values[] = {
-2.302585092994046,   -1.609437912434100,   -1.203972804325936,
-0.916290731874155,   -0.693147180559945,   -0.510825623765991,   -0.356674943938732,
-0.223143551314210,   -0.105360515657826,   -0.000000000000000,    0.095310179804325,
0.182321556793955,    0.262364264467491,    0.336472236621213,    0.405465108108165,
0.470003629245736,    0.530628251062171,    0.587786664902119,    0.641853886172395};
int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x,  double y);
long double s21_log(double x);
long double s21_pow(double base,  double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);
long double do_acos(double(x));
long double do_asin(double(y));
long double do_atan(double(y));
long double* rotate_counterclockwise(long double *buff,  int i);
long double* rotate_clockwise(long double *buff,  int i);
double* reduce_argument_1(double *buff,  double x);
int reduce_argument_2(double x);
long double do_exp(double x);
double rough_estimation(double s);
double* reduce_trig_argument_1(double x,  double *buff);
int reduce_trig_argument_2(const double *buff);
long double do_sin(double x);
long double do_cos(double x);
#endif  // SRC_S21_MATH_H_