import type { SidebarConfig } from "@vuepress/theme-default";

export const sidebartw: SidebarConfig = {
	"/": [
		{
			text: "首頁",
			collapsible: true,
			children: ["/"],
		},
	],
};
