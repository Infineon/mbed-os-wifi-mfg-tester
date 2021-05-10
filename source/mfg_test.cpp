/*
 * Copyright 2021, Cypress Semiconductor Corporation (an Infineon company) or
 * an affiliate of Cypress Semiconductor Corporation.  All rights reserved.
 *
 * This software, including source code, documentation and related
 * materials ("Software") is owned by Cypress Semiconductor Corporation
 * or one of its affiliates ("Cypress") and is protected by and subject to
 * worldwide patent protection (United States and foreign),
 * United States copyright laws and international treaty provisions.
 * Therefore, you may use this Software only as provided in the license
 * agreement accompanying the software package from which you
 * obtained this Software ("EULA").
 * If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
 * non-transferable license to copy, modify, and compile the Software
 * source code solely for use in connection with Cypress's
 * integrated circuit products.  Any reproduction, modification, translation,
 * compilation, or representation of this Software except as specified
 * above is prohibited without the express written permission of Cypress.
 *
 * Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress
 * reserves the right to make changes to the Software without notice. Cypress
 * does not assume any liability arising out of the application or use of the
 * Software or any product or circuit described in the Software. Cypress does
 * not authorize its products for use in any products where a malfunction or
 * failure of the Cypress product may reasonably be expected to result in
 * significant property damage, injury or death ("High Risk Product"). By
 * including Cypress's product in a High Risk Product, the manufacturer
 * of such system or application assumes all risk of such use and in doing
 * so agrees to indemnify Cypress against all liability.
 */

#include "mbed.h"
#include "mfg_test.h"
#include "WhdSTAInterface.h"
#include "mfg_test_common_api.h"

/******************************************************
 *                      Macros
 ******************************************************/

/******************************************************
 *                    Constants
 ******************************************************/
#define IOCTL_MED_LEN     (8192)

/******************************************************
 *                   Enumerations
 ******************************************************/

/******************************************************
 *                 Type Definitions
 ******************************************************/

/******************************************************
 *                    Structures
 ******************************************************/

/******************************************************
 *               Static Function Declarations
 ******************************************************/

/******************************************************
 *               Function Declarations
 ******************************************************/
void wl_set_sta_interface_handle( void *interface);

/******************************************************
 *               Variable Definitions
 ******************************************************/
static WhdSTAInterface *wifiInterface;
static WHD_EMAC emac_intf;
static unsigned char buf[IOCTL_MED_LEN] = {0};

/******************************************************
 *               Function Definitions
 ******************************************************/
#ifdef __cplusplus
extern "C" {
#endif


int main(void)
{
    int result = 0;
    uint8_t mac[ETHER_ADDR_LENGTH] = {0};

    /* Turn Wifi ON */
    wifiInterface = ( WhdSTAInterface *) WiFiInterface::get_default_instance();
    if (!wifiInterface)
    {
        printf("ERROR: No networkInterface found.\n");
        return -1;
    }
    wifiInterface->wifi_on();
    emac_intf = WHD_EMAC::get_instance();
    emac_intf.get_hwaddr(mac);

    emac_intf.set_link_input_cb(NULL);
    emac_intf.set_link_state_cb(NULL);
    emac_intf.activity_cb = NULL;
    printf("MFG TEST APPLICATION H/W MAC: %02x:%02x:%02x:%02x:%02x:%02x",
    		mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);

    wl_set_sta_interface_handle(emac_intf.ifp);

    while (true)
    {
        memset(buf, 0, sizeof(buf));
        wl_remote_command_handler( buf);
    } /* end of while(true) */

    return result;
}

#ifdef __cplusplus
}
#endif
