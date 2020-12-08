/* SPDX-License-Identifier: BSD-3-Clause OR GPL-2.0
 *
 * Copyright (c) 2019-2020 Marvell International Ltd. All rights reserved.
 *
 */
#include "prestera_log.h"

static const char unknown[] = "UNKNOWN";

DEF_ENUM_MAP(netdev_cmd) = {
	[NETDEV_UP] = "NETDEV_UP",
	[NETDEV_DOWN] = "NETDEV_DOWN",
	[NETDEV_REBOOT] = "NETDEV_REBOOT",
	[NETDEV_CHANGE] = "NETDEV_CHANGE",
	[NETDEV_REGISTER] = "NETDEV_REGISTER",
	[NETDEV_UNREGISTER] = "NETDEV_UNREGISTER",
	[NETDEV_CHANGEMTU] = "NETDEV_CHANGEMTU",
	[NETDEV_CHANGEADDR] = "NETDEV_CHANGEADDR",
	[NETDEV_PRE_CHANGEADDR] = "NETDEV_PRE_CHANGEADDR",
	[NETDEV_GOING_DOWN] = "NETDEV_GOING_DOWN",
	[NETDEV_CHANGENAME] = "NETDEV_CHANGENAME",
	[NETDEV_FEAT_CHANGE] = "NETDEV_FEAT_CHANGE",
	[NETDEV_BONDING_FAILOVER] = "NETDEV_BONDING_FAILOVER",
	[NETDEV_PRE_UP] = "NETDEV_PRE_UP",
	[NETDEV_PRE_TYPE_CHANGE] = "NETDEV_PRE_TYPE_CHANGE",
	[NETDEV_POST_TYPE_CHANGE] = "NETDEV_POST_TYPE_CHANGE",
	[NETDEV_POST_INIT] = "NETDEV_POST_INIT",
	[NETDEV_RELEASE] = "NETDEV_RELEASE",
	[NETDEV_NOTIFY_PEERS] = "NETDEV_NOTIFY_PEERS",
	[NETDEV_JOIN] = "NETDEV_JOIN",
	[NETDEV_CHANGEUPPER] = "NETDEV_CHANGEUPPER",
	[NETDEV_RESEND_IGMP] = "NETDEV_RESEND_IGMP",
	[NETDEV_PRECHANGEMTU] = "NETDEV_PRECHANGEMTU",
	[NETDEV_CHANGEINFODATA] = "NETDEV_CHANGEINFODATA",
	[NETDEV_BONDING_INFO] = "NETDEV_BONDING_INFO",
	[NETDEV_PRECHANGEUPPER] = "NETDEV_PRECHANGEUPPER",
	[NETDEV_CHANGELOWERSTATE] = "NETDEV_CHANGELOWERSTATE",
	[NETDEV_UDP_TUNNEL_PUSH_INFO] = "NETDEV_UDP_TUNNEL_PUSH_INFO",
	[NETDEV_UDP_TUNNEL_DROP_INFO] = "NETDEV_UDP_TUNNEL_DROP_INFO",
	[NETDEV_CHANGE_TX_QUEUE_LEN] = "NETDEV_CHANGE_TX_QUEUE_LEN",
	[NETDEV_CVLAN_FILTER_PUSH_INFO] = "NETDEV_CVLAN_FILTER_PUSH_INFO",
	[NETDEV_CVLAN_FILTER_DROP_INFO] = "NETDEV_CVLAN_FILTER_DROP_INFO",
	[NETDEV_SVLAN_FILTER_PUSH_INFO] = "NETDEV_SVLAN_FILTER_PUSH_INFO",
	[NETDEV_SVLAN_FILTER_DROP_INFO] = "NETDEV_SVLAN_FILTER_DROP_INFO"
};

DEF_ENUM_MAP(switchdev_notifier_type) = {
	[SWITCHDEV_FDB_ADD_TO_BRIDGE] = "SWITCHDEV_FDB_ADD_TO_BRIDGE",
	[SWITCHDEV_FDB_DEL_TO_BRIDGE] = "SWITCHDEV_FDB_DEL_TO_BRIDGE",
	[SWITCHDEV_FDB_ADD_TO_DEVICE] = "SWITCHDEV_FDB_ADD_TO_DEVICE",
	[SWITCHDEV_FDB_DEL_TO_DEVICE] = "SWITCHDEV_FDB_DEL_TO_DEVICE",
	[SWITCHDEV_FDB_OFFLOADED] = "SWITCHDEV_FDB_OFFLOADED",
	[SWITCHDEV_PORT_OBJ_ADD] = "SWITCHDEV_PORT_OBJ_ADD",
	[SWITCHDEV_PORT_OBJ_DEL] = "SWITCHDEV_PORT_OBJ_DEL",
	[SWITCHDEV_PORT_ATTR_SET] = "SWITCHDEV_PORT_ATTR_SET",
	[SWITCHDEV_VXLAN_FDB_ADD_TO_BRIDGE] =
		"SWITCHDEV_VXLAN_FDB_ADD_TO_BRIDGE",
	[SWITCHDEV_VXLAN_FDB_DEL_TO_BRIDGE] =
		"SWITCHDEV_VXLAN_FDB_DEL_TO_BRIDGE",
	[SWITCHDEV_VXLAN_FDB_ADD_TO_DEVICE] =
		"SWITCHDEV_VXLAN_FDB_ADD_TO_DEVICE",
	[SWITCHDEV_VXLAN_FDB_DEL_TO_DEVICE] =
		"SWITCHDEV_VXLAN_FDB_DEL_TO_DEVICE",
	[SWITCHDEV_VXLAN_FDB_OFFLOADED] = "SWITCHDEV_VXLAN_FDB_OFFLOADED"
};

DEF_ENUM_MAP(switchdev_attr_id) = {
	[SWITCHDEV_ATTR_ID_UNDEFINED] =
		"SWITCHDEV_ATTR_ID_UNDEFINED",
	[SWITCHDEV_ATTR_ID_PORT_STP_STATE] =
		"SWITCHDEV_ATTR_ID_PORT_STP_STATE",
	[SWITCHDEV_ATTR_ID_PORT_BRIDGE_FLAGS] =
		"SWITCHDEV_ATTR_ID_PORT_BRIDGE_FLAGS",
	[SWITCHDEV_ATTR_ID_PORT_PRE_BRIDGE_FLAGS] =
		"SWITCHDEV_ATTR_ID_PORT_PRE_BRIDGE_FLAGS",
	[SWITCHDEV_ATTR_ID_PORT_MROUTER] =
		"SWITCHDEV_ATTR_ID_PORT_MROUTER",
	[SWITCHDEV_ATTR_ID_BRIDGE_AGEING_TIME] =
		"SWITCHDEV_ATTR_ID_BRIDGE_AGEING_TIME",
	[SWITCHDEV_ATTR_ID_BRIDGE_VLAN_FILTERING] =
		"SWITCHDEV_ATTR_ID_BRIDGE_VLAN_FILTERING",
	[SWITCHDEV_ATTR_ID_BRIDGE_MC_DISABLED] =
		"SWITCHDEV_ATTR_ID_BRIDGE_MC_DISABLED",
	[SWITCHDEV_ATTR_ID_BRIDGE_MROUTER] =
		"SWITCHDEV_ATTR_ID_BRIDGE_MROUTER"
};

DEF_ENUM_MAP(switchdev_obj_id) = {
	[SWITCHDEV_OBJ_ID_UNDEFINED] = "SWITCHDEV_OBJ_ID_UNDEFINED",
	[SWITCHDEV_OBJ_ID_PORT_VLAN] = "SWITCHDEV_OBJ_ID_PORT_VLAN",
	[SWITCHDEV_OBJ_ID_PORT_MDB] = "SWITCHDEV_OBJ_ID_PORT_MDB",
	[SWITCHDEV_OBJ_ID_HOST_MDB] = "SWITCHDEV_OBJ_ID_HOST_MDB",
};

DEF_ENUM_MAP(fib_event_type) = {
	[FIB_EVENT_ENTRY_REPLACE] = "FIB_EVENT_ENTRY_REPLACE",
	[FIB_EVENT_ENTRY_APPEND] = "FIB_EVENT_ENTRY_APPEND",
	[FIB_EVENT_ENTRY_ADD] = "FIB_EVENT_ENTRY_ADD",
	[FIB_EVENT_ENTRY_DEL] = "FIB_EVENT_ENTRY_DEL",
	[FIB_EVENT_RULE_ADD] = "FIB_EVENT_RULE_ADD",
	[FIB_EVENT_RULE_DEL] = "FIB_EVENT_RULE_DEL",
	[FIB_EVENT_NH_ADD] = "FIB_EVENT_NH_ADD",
	[FIB_EVENT_NH_DEL] = "FIB_EVENT_NH_DEL",
	[FIB_EVENT_VIF_ADD] = "FIB_EVENT_VIF_ADD",
	[FIB_EVENT_VIF_DEL] = "FIB_EVENT_VIF_DEL",
};

DEF_ENUM_MAP(netevent_notif_type) = {
	[NETEVENT_NEIGH_UPDATE] = "NETEVENT_NEIGH_UPDATE",
	[NETEVENT_REDIRECT] = "NETEVENT_REDIRECT",
	[NETEVENT_DELAY_PROBE_TIME_UPDATE] =
		"NETEVENT_DELAY_PROBE_TIME_UPDATE",
	[NETEVENT_IPV4_MPATH_HASH_UPDATE] =
		"NETEVENT_IPV4_MPATH_HASH_UPDATE",
	[NETEVENT_IPV6_MPATH_HASH_UPDATE] =
		"NETEVENT_IPV6_MPATH_HASH_UPDATE",
	[NETEVENT_IPV4_FWD_UPDATE_PRIORITY_UPDATE] =
		"NETEVENT_IPV4_FWD_UPDATE_PRIORITY_UPDATE",
};

DEF_ENUM_MAP(tc_setup_type) = {
	[TC_SETUP_QDISC_MQPRIO] = "TC_SETUP_QDISC_MQPRIO",
	[TC_SETUP_CLSU32] = "TC_SETUP_CLSU32",
	[TC_SETUP_CLSFLOWER] = "TC_SETUP_CLSFLOWER",
	[TC_SETUP_CLSMATCHALL] = "TC_SETUP_CLSMATCHALL",
	[TC_SETUP_CLSBPF] = "TC_SETUP_CLSBPF",
	[TC_SETUP_BLOCK] = "TC_SETUP_BLOCK",
	[TC_SETUP_QDISC_CBS] = "TC_SETUP_QDISC_CBS",
	[TC_SETUP_QDISC_RED] = "TC_SETUP_QDISC_RED",
	[TC_SETUP_QDISC_PRIO] = "TC_SETUP_QDISC_PRIO",
	[TC_SETUP_QDISC_MQ] = "TC_SETUP_QDISC_MQ",
	[TC_SETUP_QDISC_ETF] = "TC_SETUP_QDISC_ETF",
	[TC_SETUP_ROOT_QDISC] = "TC_SETUP_ROOT_QDISC",
	[TC_SETUP_QDISC_GRED] = "TC_SETUP_QDISC_GRED",
};

DEF_ENUM_MAP(flow_block_binder_type) = {
	[FLOW_BLOCK_BINDER_TYPE_UNSPEC] =
		"FLOW_BLOCK_BINDER_TYPE_UNSPEC",
	[FLOW_BLOCK_BINDER_TYPE_CLSACT_INGRESS] =
		"FLOW_BLOCK_BINDER_TYPE_CLSACT_INGRESS",
	[FLOW_BLOCK_BINDER_TYPE_CLSACT_EGRESS] =
		"FLOW_BLOCK_BINDER_TYPE_CLSACT_EGRESS",
};

DEF_ENUM_MAP(tc_matchall_command) = {
	[TC_CLSMATCHALL_REPLACE] = "TC_CLSMATCHALL_REPLACE",
	[TC_CLSMATCHALL_DESTROY] = "TC_CLSMATCHALL_DESTROY",
	[TC_CLSMATCHALL_STATS] = "TC_CLSMATCHALL_STATS",
};

DEF_ENUM_MAP(flow_cls_command) = {
	[FLOW_CLS_REPLACE] = "FLOW_CLS_REPLACE",
	[FLOW_CLS_DESTROY] = "FLOW_CLS_DESTROY",
	[FLOW_CLS_STATS] = "FLOW_CLS_STATS",
	[FLOW_CLS_TMPLT_CREATE] = "FLOW_CLS_TMPLT_CREATE",
	[FLOW_CLS_TMPLT_DESTROY] = "FLOW_CLS_TMPLT_DESTROY",
};

DEF_ENUM_MAP(flow_action_id) = {
	[FLOW_ACTION_ACCEPT] = "FLOW_ACTION_ACCEPT",
	[FLOW_ACTION_DROP] = "FLOW_ACTION_DROP",
	[FLOW_ACTION_TRAP] = "FLOW_ACTION_TRAP",
	[FLOW_ACTION_GOTO] = "FLOW_ACTION_GOTO",
	[FLOW_ACTION_REDIRECT] = "FLOW_ACTION_REDIRECT",
	[FLOW_ACTION_MIRRED] = "FLOW_ACTION_MIRRED",
	[FLOW_ACTION_VLAN_PUSH] = "FLOW_ACTION_VLAN_PUSH",
	[FLOW_ACTION_VLAN_POP] = "FLOW_ACTION_VLAN_POP",
	[FLOW_ACTION_VLAN_MANGLE] = "FLOW_ACTION_VLAN_MANGLE",
	[FLOW_ACTION_TUNNEL_ENCAP] = "FLOW_ACTION_TUNNEL_ENCAP",
	[FLOW_ACTION_TUNNEL_DECAP] = "FLOW_ACTION_TUNNEL_DECAP",
	[FLOW_ACTION_MANGLE] = "FLOW_ACTION_MANGLE",
	[FLOW_ACTION_ADD] = "FLOW_ACTION_ADD",
	[FLOW_ACTION_CSUM] = "FLOW_ACTION_CSUM",
	[FLOW_ACTION_MARK] = "FLOW_ACTION_MARK",
	[FLOW_ACTION_WAKE] = "FLOW_ACTION_WAKE",
	[FLOW_ACTION_QUEUE] = "FLOW_ACTION_QUEUE",
	[FLOW_ACTION_SAMPLE] = "FLOW_ACTION_SAMPLE",
	[FLOW_ACTION_POLICE] = "FLOW_ACTION_POLICE",
	[FLOW_ACTION_CT] = "FLOW_ACTION_CT",
};

DEF_ENUM_FUNC(netdev_cmd, NETDEV_UP, NETDEV_SVLAN_FILTER_DROP_INFO)

DEF_ENUM_FUNC(switchdev_notifier_type, SWITCHDEV_FDB_ADD_TO_BRIDGE,
	      SWITCHDEV_VXLAN_FDB_OFFLOADED)
DEF_ENUM_FUNC(switchdev_attr_id, SWITCHDEV_ATTR_ID_UNDEFINED,
	      SWITCHDEV_ATTR_ID_BRIDGE_MROUTER)
DEF_ENUM_FUNC(switchdev_obj_id, SWITCHDEV_OBJ_ID_UNDEFINED,
	      SWITCHDEV_OBJ_ID_HOST_MDB)

DEF_ENUM_FUNC(fib_event_type, FIB_EVENT_ENTRY_REPLACE, FIB_EVENT_VIF_DEL)

DEF_ENUM_FUNC(netevent_notif_type, NETEVENT_NEIGH_UPDATE,
	      NETEVENT_IPV4_FWD_UPDATE_PRIORITY_UPDATE)

/* TC traffic control */
DEF_ENUM_FUNC(tc_setup_type, TC_SETUP_QDISC_MQPRIO, TC_SETUP_QDISC_GRED)
DEF_ENUM_FUNC(flow_block_binder_type, FLOW_BLOCK_BINDER_TYPE_UNSPEC,
	      FLOW_BLOCK_BINDER_TYPE_CLSACT_EGRESS)
DEF_ENUM_FUNC(tc_matchall_command, TC_CLSMATCHALL_REPLACE, TC_CLSMATCHALL_STATS)
DEF_ENUM_FUNC(flow_cls_command, FLOW_CLS_REPLACE, FLOW_CLS_TMPLT_DESTROY)
DEF_ENUM_FUNC(flow_action_id, FLOW_ACTION_ACCEPT, FLOW_ACTION_CT)
