import type { SidebarConfig } from "@vuepress/theme-default";

export const sidebaren: SidebarConfig = {
	"/": [
		{
			text: "Home",
			collapsible: true,
			children: [{ text: "Home", link: "/en/" }],
		},
	],
};
