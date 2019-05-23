Action()
{
	web_set_sockets_option("SSL_VERSION", "TLS1.2");
	
	web_set_max_html_param_len("9999");

	web_add_auto_header("Accept", "application/json");
	web_add_auto_header("Accept-Encoding", "gzip, deflate");
	web_add_auto_header("Accept-Language", "en-US,en;q=0.8");

	
	web_add_header("authenticationToken",lr_eval_string("{p_AuthToken}"));
	web_add_header("Root-Subscription" ,"1");
	web_add_header("Device-UID","UID-1234") ;
	web_add_header("OS-Version","7.0.0") ;
	web_add_header("Manufacturer","Samsung") ;
	web_add_header("Platform","Android") ;
	web_add_header("Device-Model","Galaxy S3");
	web_add_header("App-Version","8.0") ;
	
	lr_start_transaction("MVAX_AppStart_PAYM_01_GetAppConfig");

		web_custom_request("web_custom_request",
		"URL=https://{p_HOSTNAME}/app/api/v1/appconfig",
		"Method=GET",
		"TargetFrame=",
		"Resource=0",
		"Referer=",
		LAST);
	
	lr_end_transaction("MVAX_AppStart_PAYM_01_GetAppConfig", LR_AUTO);
	
	lr_think_time(thinktime);
	
    web_add_header("Subscription","{p_MSISDN_PayM}");
	web_add_header("authenticationToken",lr_eval_string("{p_AuthToken}"));
	web_add_header("Root-Subscription" ,"1");

	web_reg_save_param("c_hansoloToken", "LB=\"mspHansoloToken\":\"", "RB=\"", LAST);
	
	lr_start_transaction("MVAX_AppStart_PAYM_02_GetHansoloToken");

		web_custom_request("web_custom_request",
		"URL=https://{p_HOSTNAME}/app/api/v1/testHansolo",
		"Method=GET",
		"TargetFrame=",
		"Resource=0",
		"Referer=",
		LAST);

	lr_end_transaction("MVAX_AppStart_PAYM_02_GetHansoloToken", LR_AUTO); 

	lr_think_time(thinktime);
	
	web_add_header("Msp-Hansolo-Token",lr_eval_string("{c_hansoloToken}"));
    web_add_header("Subscription","{p_MSISDN_PayM}");
	web_add_header("authenticationToken",lr_eval_string("{p_AuthToken}"));
	web_add_header("Root-Subscription" ,"1");
	
	
	web_reg_save_param_ex(
		"ParamName=c_JWTSoftToken",
		"LB=\"backendJwtSoftToken\":\"",
		"RB=\"",
		SEARCH_FILTERS,
		LAST);

	lr_start_transaction("MVAX_AppStart_PAYM_03_SoftToken");

		web_custom_request("web_custom_request",
		"URL=https://{p_HOSTNAME}/app/api/v1/softToken",
		"Method=GET",
		"TargetFrame=",
		"Resource=0",
		"Referer=",
		"Body=",
		LAST);

	lr_end_transaction("MVAX_AppStart_PAYM_03_SoftToken", LR_AUTO); 

	lr_think_time(thinktime);
	
    web_add_header("Subscription","{p_MSISDN_PayM}");
	web_add_header("authenticationToken",lr_eval_string("{p_AuthToken}"));
	web_add_header("Root-Subscription" ,"1");
	web_add_header("Device-UID","amruta") ;
	web_add_header("OS-Version","7") ;
	web_add_header("Manufacturer","Samsung") ;
	web_add_header("Platform","Android") ;
	web_add_header("Device-Model","Galaxy S3");
	web_add_header("App-Version","8") ;
	web_add_header("JWT","{c_JWTSoftToken}") ;

	lr_start_transaction("MVAX_AppStart_PAYM_04_GetSegment");

		web_custom_request("web_custom_request",
		"URL=https://{p_HOSTNAME}/app/api/v1/segment",
		"Method=GET",
		"TargetFrame=",
		"Resource=0",
		"Referer=",
		"Body=",
		LAST);

	lr_end_transaction("MVAX_AppStart_PAYM_04_GetSegment", LR_AUTO);

	lr_think_time(thinktime);
	
	web_add_header("Subscription","{p_MSISDN_PayM}");
	web_add_header("authenticationToken",lr_eval_string("{p_AuthToken}"));
	web_add_header("Root-Subscription" ,"1");
	web_add_header("Device-UID","UID-1234") ;
	web_add_header("OS-Version","7.0.0") ;
	web_add_header("Manufacturer","Samsung") ;
	web_add_header("Platform","Android") ;
	web_add_header("Device-Model","Galaxy S3");
	web_add_header("App-Version","8.0") ;
	web_add_header("segment","PAYG" ) ;
	web_add_header("subscription-type","MPS") ;
	
	lr_start_transaction("MVAX_AppStart_PAYM_05_GetSubConfig");

		web_custom_request("web_custom_request",
		"URL=https://{p_HOSTNAME}/app/api/v1/subsConfig",
		"Method=GET",
		"TargetFrame=",
		"Resource=0",
		"Referer=",
		"Body=",
		LAST);

	lr_end_transaction("MVAX_AppStart_PAYM_05_GetSubConfig", LR_AUTO); 
 
	lr_think_time(thinktime);
	
	web_add_header("Subscription","{p_MSISDN_PayM}");
	web_add_header("authenticationToken",lr_eval_string("{p_AuthToken}"));
	web_add_header("Root-Subscription" ,"1");
	web_add_header("Device-UID","UID-1234") ;
	web_add_header("OS-Version","7.0.0") ;
	web_add_header("Manufacturer","Samsung") ;
	web_add_header("Platform","Android") ;
	web_add_header("Device-Model","Galaxy S3");
	web_add_header("App-Version","8.0") ;
	web_add_header("segment","CONSUMER" ) ;
	web_add_header("subscription-type","MPS") ;
	web_add_header("JWT","{c_JWTSoftToken}") ;
	web_add_header("Cached","false");
	
	lr_start_transaction("MVAX_AppStart_PAYM_06_GetDashboard");

		web_custom_request("web_custom_request",
		"URL=https://{p_HOSTNAME}/app/api/v1/dashboard",
		"Method=GET",
		"TargetFrame=",
		"Resource=0",
		"Referer=",
		"Body=",
		LAST);

	lr_end_transaction("MVAX_AppStart_PAYM_06_GetDashboard", LR_AUTO); 
 
	return 0;
}